#include "compat.h"

#include <QDateTime>
#include <QTimer>
#include <QDebug>
#include <QFile>
#include <boost/bind.hpp>
#include <boost/filesystem/path.hpp>

#include "bantablemodel.h"
#include "guiconstants.h"
#include "optionsmodel.h"
#include "addresstablemodel.h"
#include "peertablemodel.h"
#include "transactiontablemodel.h"
#include "cchainparams.h"
#include "chainparams.h"
#include "calert.h"
#include "masternodeman.h"
#include "masternode_extern.h"
#include "cblock.h"
#include "net/cnode.h"
#include "net.h"
#include "main.h"
#include "main_extern.h"
#include "cblockindex.h"
#include "util.h"
#include "cmasternodeman.h"
#include "thread.h"
#include "enums/changetype.h"
#include "ui_interface.h"

#include "clientmodel.h"

static const int64_t nClientStartupTime = GetTime();

ClientModel::ClientModel(OptionsModel *optionsModel, QObject *parent) :
    QObject(parent),
    optionsModel(optionsModel),
    peerTableModel(0),
    banTableModel(0),
    cachedNumBlocks(0),
    numBlocksAtStartup(-1),
    cachedMasternodeCountString(""),
    pollTimer(0)
{
    peerTableModel = new PeerTableModel(this);
    banTableModel = new BanTableModel(this);
    pollTimer = new QTimer(this);
    pollTimer->setInterval(MODEL_UPDATE_DELAY);
    pollTimer->start();
    connect(pollTimer, SIGNAL(timeout()), this, SLOT(updateTimer()));

    pollMnTimer = new QTimer(this);
    connect(pollMnTimer, SIGNAL(timeout()), this, SLOT(updateMnTimer()));
    // no need to update as frequent as data for balances/txes/blocks
    pollMnTimer->start(MODEL_UPDATE_DELAY * 4);

    subscribeToCoreSignals();
}

ClientModel::~ClientModel()
{
    unsubscribeFromCoreSignals();
}

int ClientModel::getNumConnections() const
{
    return vNodes.size();
}

QString ClientModel::getMasternodeCountString() const
{
    return QString::number((int)mnodeman.CountEnabled()) + " / " + QString::number((int)mnodeman.size());
}

int ClientModel::getNumBlocks() const
{
    LOCK(cs_main);
    return nBestHeight;
}

int ClientModel::getNumBlocksAtStartup()
{
    if (numBlocksAtStartup == -1) numBlocksAtStartup = getNumBlocks();
    return numBlocksAtStartup;
}

quint64 ClientModel::getTotalBytesRecv() const
{
    return CNode::GetTotalBytesRecv();
}

quint64 ClientModel::getTotalBytesSent() const
{
    return CNode::GetTotalBytesSent();
}

QDateTime ClientModel::getLastBlockDate() const
{
    LOCK(cs_main);
    if (pindexBest)
        return QDateTime::fromTime_t(pindexBest->GetBlockTime());
    else
        return QDateTime::fromTime_t(Params().GenesisBlock().nTime); // Genesis block's time of current network
}


void ClientModel::updateTimer()
{
    // Get required lock upfront. This avoids the GUI from getting stuck on
    // periodical polls if the core is holding the locks for a longer time -
    // for example, during a wallet rescan.
    TRY_LOCK(cs_main, lockMain);
    if(!lockMain)
        return;
    // Some quantities (such as number of blocks) change so fast that we don't want to be notified for each change.
    // Periodically check and update with a timer.
    int newNumBlocks = getNumBlocks();

    if(cachedNumBlocks != newNumBlocks)
    {
        cachedNumBlocks = newNumBlocks;

        emit numBlocksChanged(newNumBlocks);
    }

    emit bytesChanged(getTotalBytesRecv(), getTotalBytesSent());
}

void ClientModel::updateMnTimer()
{
    // Get required lock upfront. This avoids the GUI from getting stuck on
    // periodical polls if the core is holding the locks for a longer time -
    // for example, during a wallet rescan.
    TRY_LOCK(cs_main, lockMain);
    if(!lockMain)
        return;
    QString newMasternodeCountString = getMasternodeCountString();

    if (cachedMasternodeCountString != newMasternodeCountString)
    {
        cachedMasternodeCountString = newMasternodeCountString;

        emit strMasternodesChanged(cachedMasternodeCountString);
    }
}

void ClientModel::updateNumConnections(int numConnections)
{
    emit numConnectionsChanged(numConnections);
}

void ClientModel::updateAlert(const QString &hash, int status)
{
    // Show error message notification for new alert
    if(status == CT_NEW)
    {
        uint256 hash_256;
        hash_256.SetHex(hash.toStdString());
        CAlert alert = CAlert::getAlertByHash(hash_256);
        if(!alert.IsNull())
        {
            emit message(tr("Network Alert"), QString::fromStdString(alert.strStatusBar), false, CClientUIInterface::ICON_ERROR);
        }
    }

    emit alertsChanged(getStatusBarWarnings());
}

bool ClientModel::isTestNet() const
{
    return TestNet();
}

bool ClientModel::inInitialBlockDownload() const
{
    return IsInitialBlockDownload();
}

bool ClientModel::isImporting() const
{
    return fImporting;
}

QString ClientModel::getStatusBarWarnings() const
{
    return QString::fromStdString(GetWarnings("statusbar"));
}

OptionsModel *ClientModel::getOptionsModel()
{
    return optionsModel;
}

PeerTableModel *ClientModel::getPeerTableModel()
{
    return peerTableModel;
}

BanTableModel *ClientModel::getBanTableModel()
{
    return banTableModel;
}

QString ClientModel::formatFullVersion() const
{
    return QString::fromStdString(FormatFullVersion());
}

QString ClientModel::formatBuildDate() const
{
    return QString::fromStdString(CLIENT_DATE);
}

bool ClientModel::isReleaseVersion() const
{
    return CLIENT_VERSION_IS_RELEASE;
}

QString ClientModel::clientName() const
{
    return QString::fromStdString(CLIENT_NAME);
}

QString ClientModel::formatClientStartupTime() const
{
    return QDateTime::fromTime_t(nClientStartupTime).toString();
}

QString ClientModel::getConfigFileContent() const
{
    QString result;

    boost::filesystem::path path = GetConfigFile();
    QString pathString = QString::fromStdString(path.string());
    QFile file(pathString);
    
    if (file.exists())
    {
        QString line;
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream stream(&file);
            while (!stream.atEnd())
            {
                line = stream.readLine();
                result += line + "\n";
            }   
        }
    }

    file.close();
    return result;
}

void ClientModel::setConfigFileContent(const QString &content)
{
    boost::filesystem::path path = GetConfigFile();
    QString pathString = QString::fromStdString(path.string());
    QFile file(pathString);
    
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        stream << content;
    }

    file.close();
}

void ClientModel::updateBanlist()
{
    banTableModel->refresh();
}

// Handlers for core signals
static void ShowProgress(ClientModel *clientmodel, const std::string &title, int nProgress)
{
    // emits signal "showProgress"
    QMetaObject::invokeMethod(clientmodel, "showProgress", Qt::QueuedConnection,
                              Q_ARG(QString, QString::fromStdString(title)),
                              Q_ARG(int, nProgress));
}

static void NotifyNumConnectionsChanged(ClientModel *clientmodel, int newNumConnections)
{
    // Too noisy: qDebug() << "NotifyNumConnectionsChanged : " + QString::number(newNumConnections);
    QMetaObject::invokeMethod(clientmodel, "updateNumConnections", Qt::QueuedConnection,
                              Q_ARG(int, newNumConnections));
}

static void NotifyAlertChanged(ClientModel *clientmodel, const uint256 &hash, ChangeType status)
{
    qDebug() << "NotifyAlertChanged : " + QString::fromStdString(hash.GetHex()) + " status=" + QString::number(status);
    QMetaObject::invokeMethod(clientmodel, "updateAlert", Qt::QueuedConnection,
                              Q_ARG(QString, QString::fromStdString(hash.GetHex())),
                              Q_ARG(int, status));
}

static void BannedListChanged(ClientModel *clientmodel)
{
    qDebug() << QString("%1: Requesting update for peer banlist").arg(__func__);
    QMetaObject::invokeMethod(clientmodel, "updateBanlist", Qt::QueuedConnection);
}

void ClientModel::subscribeToCoreSignals()
{
    // Connect signals to client
    uiInterface.ShowProgress.connect(boost::bind(ShowProgress, this, _1, _2));
    uiInterface.NotifyNumConnectionsChanged.connect(boost::bind(NotifyNumConnectionsChanged, this, _1));
    uiInterface.NotifyAlertChanged.connect(boost::bind(NotifyAlertChanged, this, _1, _2));
}

void ClientModel::unsubscribeFromCoreSignals()
{
    // Disconnect signals from client
    uiInterface.ShowProgress.disconnect(boost::bind(ShowProgress, this, _1, _2));
    uiInterface.NotifyNumConnectionsChanged.disconnect(boost::bind(NotifyNumConnectionsChanged, this, _1));
    uiInterface.NotifyAlertChanged.disconnect(boost::bind(NotifyAlertChanged, this, _1, _2));
    uiInterface.BannedListChanged.disconnect(boost::bind(BannedListChanged, this));
}

#include "rpcprotocol.h"
#include "net.h"
#include "net/cnodestats.h"
#include "cblock.h"
#include "ctransaction.h"
#include "ctxout.h"
#include "ctxin.h"
#include "main_const.h"
#include "cpubkey.h"
#include "init.h"
#include "cwallet.h"
#include "cmasternodepayments.h"
#include "util.h"
#include "chainparams.h"
#include "cchainparams.h"
#include "cbignum.h"
#include "main_extern.h"
#include "cblockindex.h"

json_spirit::Value mintblock(const json_spirit::Array& params, bool fHelp)
{
	CBlock block;
	std::vector<CTxIn> vin;
	std::vector<CTxOut> vout;
	CPubKey pubkey = pwalletMain->vchDefaultKey;
	
	vin.resize(1);
    vin[0].prevout.SetNull();
	
	vout.push_back(CTxOut(1000000000 * COIN, CScript() << pubkey));
	
	block.vtx.push_back(CTransaction(CTransaction::CURRENT_VERSION, 0, vin, vout, 0));
	
	//block.nHeight  = pindexBest->nHeight + 1;
	block.hashPrevBlock = pindexBest->GetBlockHash();
	block.hashMerkleRoot = block.BuildMerkleTree();
	block.nVersion = 7;
	block.nTime    = GetTime();
	block.nBits    = 0xdeadbeef;
	block.nNonce   = 1337;
	
	bool fAccepted = ProcessBlock(NULL, &block);
    if (!fAccepted)
	{
        return "rejected";
	}
	
	return block.ToString();
}




/*
// Example
json_spirit::Value mintblock(const json_spirit::Array& params, bool fHelp)
{
	CNodeStats stats;
	
	pnodeLocalHost->copyStats(stats);
	
	return stats.addrName;
}
*/
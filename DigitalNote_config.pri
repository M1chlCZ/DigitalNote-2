## Version
DIGITALNOTE_VERSION_MAJOR = 2
DIGITALNOTE_VERSION_MINOR = 0
DIGITALNOTE_VERSION_REVISION = 0
DIGITALNOTE_VERSION_BUILD = 5

## Leveldb library
DIGITALNOTE_LEVELDB_PATH              = $${DIGITALNOTE_PATH}/src/leveldb
DIGITALNOTE_LEVELDB_INCLUDE_PATH      = $${DIGITALNOTE_PATH}/src/leveldb/include
DIGITALNOTE_LEVELDB_HELPERS_PATH      = $${DIGITALNOTE_PATH}/src/leveldb/helpers
DIGITALNOTE_LEVELDB_LIB_PATH          = $${DIGITALNOTE_PATH}/src/leveldb

## Leveldb 2.11 library
DIGITALNOTE_LEVELDB_2_11_PATH         = $${DIGITALNOTE_PATH}/src/leveldb-2.11
DIGITALNOTE_LEVELDB_2_11_INCLUDE_PATH = $${DIGITALNOTE_PATH}/src/leveldb-2.11/include
DIGITALNOTE_LEVELDB_2_11_HELPERS_PATH = $${DIGITALNOTE_PATH}/src/leveldb-2.11/helpers
DIGITALNOTE_LEVELDB_2_11_LIB_PATH     = $${DIGITALNOTE_PATH}/src/leveldb-2.11/build

## Secp256K1 library
DIGITALNOTE_SECP256K1_PATH            = $${DIGITALNOTE_PATH}/src/secp256k1
DIGITALNOTE_SECP256K1_INCLUDE_PATH    = $${DIGITALNOTE_PATH}/src/secp256k1/include
DIGITALNOTE_SECP256K1_LIB_PATH        = $${DIGITALNOTE_PATH}/src/secp256k1/.libs

win32 {
	## Boost
	DIGITALNOTE_BOOST_PATH            = $${DIGITALNOTE_PATH}/../libs/boost_1_75_0
	DIGITALNOTE_BOOST_INCLUDE_PATH    = $${DIGITALNOTE_PATH}/../libs/boost_1_75_0
	DIGITALNOTE_BOOST_LIB_PATH        = $${DIGITALNOTE_PATH}/../libs/boost_1_75_0/stage/lib
	DIGITALNOTE_BOOST_SUFFIX          = -mgw7-mt-d-x64-1_75
	
	## OpenSSL library
	DIGITALNOTE_OPENSSL_PATH          = $${DIGITALNOTE_PATH}/../libs/openssl-1.0.2u
	DIGITALNOTE_OPENSSL_INCLUDE_PATH  = $${DIGITALNOTE_PATH}/../libs/openssl-1.0.2u/include
	DIGITALNOTE_OPENSSL_LIB_PATH      = $${DIGITALNOTE_PATH}/../libs/openssl-1.0.2u
	
	## Berkeley db library
	DIGITALNOTE_BDB_PATH              = $${DIGITALNOTE_PATH}/../libs/db-6.2.32.NC
	DIGITALNOTE_BDB_INCLUDE_PATH      = $${DIGITALNOTE_PATH}/../libs/db-6.2.32.NC/build_unix
	DIGITALNOTE_BDB_LIB_PATH          = $${DIGITALNOTE_PATH}/../libs/db-6.2.32.NC/build_unix
	
	## Event library
	DIGITALNOTE_EVENT_PATH            = $${DIGITALNOTE_PATH}/../libs/libevent-2.1.11-stable
	DIGITALNOTE_EVENT_INCLUDE_PATH    = $${DIGITALNOTE_PATH}/../libs/libevent-2.1.11-stable/include
	DIGITALNOTE_EVENT_LIB_PATH        = $${DIGITALNOTE_PATH}/../libs/libevent-2.1.11-stable/.libs
	
	## GMP library
	DIGITALNOTE_GMP_PATH              = $${DIGITALNOTE_PATH}/../libs/gmp-6.2.1
	DIGITALNOTE_GMP_INCLUDE_PATH      = $${DIGITALNOTE_PATH}/../libs/gmp-6.2.1
	DIGITALNOTE_GMP_LIB_PATH          = $${DIGITALNOTE_PATH}/../libs/gmp-6.2.1/.libs
	
	## Miniupnp library
	DIGITALNOTE_MINIUPNP_PATH         = $${DIGITALNOTE_PATH}/../libs/miniupnpc-2.1
	DIGITALNOTE_MINIUPNP_INCLUDE_PATH = $${DIGITALNOTE_PATH}/../libs/miniupnpc-2.1/../
	DIGITALNOTE_MINIUPNP_LIB_PATH     = $${DIGITALNOTE_PATH}/../libs/miniupnpc-2.1
	
	## QREncode library
	DIGITALNOTE_QRENCODE_PATH         = $${DIGITALNOTE_PATH}/../libs/qrencode-4.1.1
	DIGITALNOTE_QRENCODE_INCLUDE_PATH = $${DIGITALNOTE_PATH}/../libs/qrencode-4.1.1
	DIGITALNOTE_QRENCODE_LIB_PATH     = $${DIGITALNOTE_PATH}/../libs/qrencode-4.1.1/.libs
}

macx {
	QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.13
	
	## Boost
	DIGITALNOTE_BOOST_PATH            = /usr/local/Cellar/boost/1.76.0
	DIGITALNOTE_BOOST_INCLUDE_PATH    = /usr/local/Cellar/boost/1.76.0/include
	DIGITALNOTE_BOOST_LIB_PATH        = /usr/local/Cellar/boost/1.76.0/lib
	DIGITALNOTE_BOOST_SUFFIX = -mt
	
	## OpenSSL library
	DIGITALNOTE_OPENSSL_PATH          = /usr/local/Cellar/openssl@1.1/1.1.1k
	DIGITALNOTE_OPENSSL_INCLUDE_PATH  = /usr/local/Cellar/openssl@1.1/1.1.1k/include
	DIGITALNOTE_OPENSSL_LIB_PATH      = /usr/local/Cellar/openssl@1.1/1.1.1k/lib
	
	## Berkeley db library
	DIGITALNOTE_BDB_PATH              = /usr/local/Cellar/berkeley-db@6.2.32
	DIGITALNOTE_BDB_INCLUDE_PATH      = /usr/local/Cellar/berkeley-db@6.2.32/include
	DIGITALNOTE_BDB_LIB_PATH          = /usr/local/Cellar/berkeley-db@6.2.32/lib
	DIGITALNOTE_LIB_BDB_SUFFIX        = -6.2
	
	## Event library
	DIGITALNOTE_EVENT_PATH            = /usr/local
	DIGITALNOTE_EVENT_INCLUDE_PATH    = /usr/local/include
	DIGITALNOTE_EVENT_LIB_PATH        = /usr/local/lib
	
	## GMP library
	DIGITALNOTE_GMP_PATH              = /usr/local
	DIGITALNOTE_GMP_INCLUDE_PATH      = /usr/local/include
	DIGITALNOTE_GMP_LIB_PATH          = /usr/local/lib
	
	## Miniupnp library
	DIGITALNOTE_MINIUPNP_PATH         = /usr/local/Cellar/miniupnpc/2.2.2
	DIGITALNOTE_MINIUPNP_INCLUDE_PATH = /usr/local/Cellar/miniupnpc/2.2.2/include
	DIGITALNOTE_MINIUPNP_LIB_PATH     = /usr/local/Cellar/miniupnpc/2.2.2/lib
	
	## QREncode library
	DIGITALNOTE_QRENCODE_PATH         = /usr/local
	DIGITALNOTE_QRENCODE_INCLUDE_PATH = /usr/local/include
	DIGITALNOTE_QRENCODE_LIB_PATH     = /usr/local/lib
}

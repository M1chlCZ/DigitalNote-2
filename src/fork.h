// Copyright (c) 2016-2020 The CryptoCoderz Team / Espers
// Copyright (c) 2018-2020 The Rubix project
// Copyright (c) 2018-2020 The DigitalNote project
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef BITCOIN_FORK_H
#define BITCOIN_FORK_H

#include <cstdint>
#include <string>
#include <map>

/** Reserve Phase start block */ 
static const int64_t nReservePhaseStart = 1;
/** Velocity toggle block */
static const int64_t VELOCITY_TOGGLE = 175; // Implementation of the Velocity system into the chain.
/** Velocity retarget toggle block */
static const int64_t VELOCITY_TDIFF = 0; // Use Velocity's retargetting method.
/** Protocol 3.0 toggle */

struct VersionInformation {
	int64_t start;
	int64_t end;
	std::string developer_address;
};

extern std::map<std::string, VersionInformation> mapVersionInformation;

#endif // BITCOIN_FORK_H

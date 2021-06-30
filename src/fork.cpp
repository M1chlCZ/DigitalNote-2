#include "fork.h"

/**
	https://www.epochconverter.com/
*/
std::map<std::string, int64_t> mapEpochToUpdateName = {
	{ "PaymentUpdate_1", 1558310400 }, // Monday, 20 May 2019 00:00:00 GMT
	{ "PaymentUpdate_2", 1562094000 }, // Tuesday, 2 July 2019 19:00:00 GMT
	{ "PaymentUpdate_3", 1562281200 }, // Thursday, 4 July 2019 23:00:00 GMT
	
	/*
		Update 2.0.0:
		- Patch security bug seesaw
		- Patch Developer wallet adress
	*/
	{ "PaymentUpdate_4", 1631232000 }, // Friday, 10 September 2021 00:00:00 GMT
	{ "PaymentUpdate_5", 1631404800 }, // Friday, 12 September 2021 00:00:00 GMT
};

std::map<std::string, std::string> mapNameToDeveloperAdress = {
	/*
		Early development adresses
	*/
	{"DevelopersAdress_unknown_1", "Dtz6UgAxwavsnxnb7jeSRj5cgERLvV8KBy"},
	{"DevelopersAdress_unknown_2", "dNXKdXpviJRV5asL2sPbsxizwfBoFgsRzq"},
	{"DevelopersAdress_unknown_3", "dPxigPi3gY3Za2crBUV2Sn2BDCrpX9eweo"},
	
	/*
		Update 1.0.0.0:
		- First developer adress
	*/
	{"DevelopersAdress_v1.0.0.0", "dSCXLHTZJJqTej8ZRszZxbLrS6dDGVJhw7"},
	
	/*
		Update v1.0.1.5:
		- Replaced developer adress for first stable release.
	*/
	{"DevelopersAdress_v1.0.1.5", "dHy3LZvqX5B2rAAoLiA7Y7rpvkLXKTkD18"},
	
	/*
		Update 2.0.0.0:
		- Because of security reasons we replaced the wallet adress to a brand new one.
	*/
	{"DevelopersAdress_v2.0.0.0", "dafC1LknpDu7eALTf5DPcnPq2dwq7f9YPE"},
};

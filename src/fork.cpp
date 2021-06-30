#include "fork.h"

/**
	https://www.epochconverter.com/
*/
std::map<std::string, VersionInformation> mapVersionInformation = {
	/*
		Early development adresses
	*/
	{
		"unknown_1",
		{
			0,
			0, 
			"Dtz6UgAxwavsnxnb7jeSRj5cgERLvV8KBy"
		}
	},
	{
		"unknown_2",
		{
			0,
			0, 
			"dNXKdXpviJRV5asL2sPbsxizwfBoFgsRzq"
		}
	},
	{
		"unknown_3",
		{
			0,
			0, 
			"dPxigPi3gY3Za2crBUV2Sn2BDCrpX9eweo"
		}
	},
	
	/*
		Update 1.0.0:
		- Add first developer address
	*/
	{
		"v1.0.0.0",
		{
			1558310400,								// Start:			Monday, 20 May 2019 00:00:00 GMT
			1558310400,								// End:				Monday, 20 May 2019 00:00:00 GMT
			"dSCXLHTZJJqTej8ZRszZxbLrS6dDGVJhw7"	// Developer Addr
		}
	},
	
	/*
		Update 1.0.1.5:
		- Change to new developer address
	*/
	{
		"v1.0.1.5",
		{
			1562094000,								// Start:			Tuesday, 2 July 2019 19:00:00 GMT
			1562281200,								// End:				Thursday, 4 July 2019 23:00:00 GMT
			"dHy3LZvqX5B2rAAoLiA7Y7rpvkLXKTkD18"	// Developer Addr
		}
	},
	
	/*
		Update 2.0.0.0:
		- Patch security bug seesaw
		- Because of security reasons we replaced the developer adress to a brand new one.
	*/
	{
		"v2.0.0.0",
		{
			1631232000,								// Start:			Friday, 10 September 2021 00:00:00 GMT
			1631404800,								// End:				Friday, 12 September 2021 00:00:00 GMT
			"dafC1LknpDu7eALTf5DPcnPq2dwq7f9YPE"	// Developer Addr
		}
	}
};

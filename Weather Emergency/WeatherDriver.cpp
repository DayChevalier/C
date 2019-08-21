//This program is built to input weather data and output weather advisories.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

#include "CountyHeader.h"
#include "CountyListHeader.h"
#include "AlertHeader.h"

int main()
{	  
	county local;
	countyList recent;
	alert warning;

	const int MAX_ARRAY = 20;
	string weatherData[MAX_ARRAY];
	string code;
	string FIPS;
	string location;
	string state = "N/A";
	string county = "N/A";
	int i = 0;

	ifstream inFile ("alerts.txt");

	if (inFile.fail() )				// Test for file's existence
    {
      cout <<  "A problem occured trying to open the file";
      exit(-1);
    }

	getline (inFile, weatherData[i]);

	while (!inFile.eof() && i <= MAX_ARRAY)
	{

		code = warning.decode(weatherData[i]);
		local.setFipsCode(code);
		FIPS = local.getFipsCode();
		location = recent.search(FIPS);

		recent.output(location, state, county);
		local.setCounty(county);
		local.setStateCode(state);


		county = local.getCounty();
		state = local.getStateCode();

		warning.warning(county, state);

		i++;
		getline (inFile, weatherData[i]);
	}

	inFile.close();

    return 0;
}
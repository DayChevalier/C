// These functions store info on one county
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

#include "CountyHeader.h"


//Default constructor
county::county()
{
	FIPS = "0";
	countyName = "N/A";
	state = "N/A";
}

//This function sets the FIPS code member
void county::setFipsCode(string fipsCode)
{
	FIPS = fipsCode;
}

//This function sets the county name member
void county::setCounty(string name)
{
	countyName = name;
}

//This function sets the state code member
void county::setStateCode(string stateCode)
{
	state = stateCode;
}

//This function gets the county code member
string county::getFipsCode()
{
	return FIPS;
}

//This function gets the county name member
string county::getCounty()
{
	return countyName;
}

//This function gets the state code member
string county::getStateCode()
{
	return state;
}
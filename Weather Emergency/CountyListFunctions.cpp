// These functions store and retrieve a county/state given a FIPS code.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

#include "countyListHeader.h"
#include "StringTokenizer.h"


//Default constructor
countyList::countyList()
{
	i = 0;

	ifstream fileData ("usfips.txt");

	if (fileData.fail() )				// Test for file's existence
    {
      cout <<  "A problem occured trying to open the file";
      exit(-1);
    }

	getline (fileData,fipsData[i]);

	while (!fileData.eof() && i <= MAX)
	{
		i++;
		getline (fileData,fipsData[i]);
	}
	fileData.close();
}


//This function finds data
string countyList::search(string location)
{
	int first = 0;
	int last = i;
	string current;

	while (first <= last)
	{
		int mid = (first + last) / 2;
		StringTokenizer decoder(fipsData[mid]);

		decoder.getStringToken();
		current = decoder.getStringToken();
		current += ",";
		current += decoder.getStringToken();

		if (location > current) 
			first = mid + 1;
		else if (location < current) 
			last = mid - 1;
		else
		{
			return fipsData[mid];
		}
	}
	return "The Search Failed";    // failed to find key
}

//This function deciphers found data
void countyList::output(string location, string &state, string &county)
{
	StringTokenizer decoder(location);

	state = decoder.getStringToken();
	location = decoder.getStringToken();
	location += decoder.getStringToken();
	county = decoder.getStringToken();

}
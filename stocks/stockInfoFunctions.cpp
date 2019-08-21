// These functions establish a stock name from a ticker

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "stockInfoHeader.h"
#include "StringTokenizer.h"

//Default constructor
stockInfo::stockInfo()
{
		input = "";
		ticker = "";
		name = "";
}

//Parameterized constructor
stockInfo::stockInfo(string data)
{
	input = data;

	StringTokenizer decoder(input, ';');

	input = decoder.getStringToken();
	SetTicker();
	input = decoder.getStringToken();
	SetName();
}

//Parameterized constructor
stockInfo::stockInfo(string tickerInput, string dateInput)
{
	ticker = tickerInput;
}

void stockInfo::getData(string data)
{
	input = data;

	StringTokenizer decoder(input, ';');

	input = decoder.getStringToken();
	SetTicker();
	input = decoder.getStringToken();
	SetName();
}



//This function sets the Ticker Code
void stockInfo::SetTicker()
{
	ticker = input;
}

//This function sets the stock name
void stockInfo::SetName()
{
	name = input;
}

//This function outputs data
void stockInfo::output()
{
	cout << "Company:" << name << endl;
}

// Overloaded less-than operator
bool stockInfo::operator< (const stockInfo& operL)
{
	bool compare = false;

	if (ticker < operL.ticker)
		compare = true;
	else
		compare = false;

	return compare;
}


// Overloaded equal-to operator
bool stockInfo::operator== (const stockInfo& operE)
{
	bool compare = false;

	if (ticker == operE.ticker)
		compare = true;
	else
		compare = false;

	return compare;
}

// These functions set stock data from a file

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

#include "stockDataHeader.h"
#include "StringTokenizer.h"

//Default constructor
stockData::stockData()
{
		input = "";
		date = "";
		convertedDate = "";
		ticker = "";
		opening = 0.0;
		high = 0.0;
		low = 0.0;
		closing = 0.0;
		exchange = 0;
		change = "";
}

//Parameterized constructor tokenizes and distributes the data to the individual sets
stockData::stockData(string data)
{
	input = data;

	StringTokenizer decoder(input);

	input = decoder.getStringToken();
	SetDate();
	input = decoder.getStringToken();
	SetTicker();
	input = decoder.getStringToken();
	SetOpening();
	input = decoder.getStringToken();
	SetHigh();
	input = decoder.getStringToken();
	SetLow();
	input = decoder.getStringToken();
	SetClosing();
	input = decoder.getStringToken();
	SetExchange();
	SetChange();
}

//Parameterized constructor for searches
stockData::stockData(string tickerInput, string dateInput)
{
	ticker = tickerInput;
	date = dateInput;
}

//This function sets a date to be converted
void stockData::SetDate()
{
	date = input;

	convertDate();
}

//converts date into mm dd, yyyy form
void stockData::convertDate()
{
	string month;
	string day;
	string year;
	string newDate;

	//substrings year from date
	year = date.substr(0,4);

	//substrings month from date and converts it into word form
	month = date.substr (4, 2);

	 if(month == "01")
	 {
		month = "January";
	 }
	 else if(month == "02")
	 {
		month = "February";
	 }
     else if(month == "03")
	 {
		month = "March";
	 }
     else if(month == "04")
	 {
		month = "April";
	 }
     else if(month == "05")
	 {
		month = "May";
	 }
     else if(month == "06")
	 {
		month = "June";
	 }
     else if(month == "07")
	 {
		month = "July";
	 }
     else if(month == "08")
	 {
		month = "August";
	 }
     else if(month == "09")
	 {
		month = "September";
	 }
     else if(month == "10")
	 {
		month = "October";
	 }
     else if(month == "11")
	 {
		month = "November";
	 }
     else if(month == "12")
	 {
		 month = "December";
	 }

	 //substrings day from date
	 day = date.substr (6);

	 //appends the changed month, day, and year into a single string
	 convertedDate = month;
	 convertedDate += " ";
	 convertedDate += day;
	 convertedDate += ", ";
	 convertedDate += year;
}

//This function sets the Ticker
void stockData::SetTicker()
{
	ticker = input;
}

//This function sets the Opening numbers
void stockData::SetOpening()
{
	opening = atof (input.c_str());
}

//This function sets the daily high
void stockData::SetHigh()
{
	high = atof (input.c_str());
}

//This function sets the daily low
void stockData::SetLow()
{
	low = atof (input.c_str());
}

//This function sets the Closing numbers
void stockData::SetClosing()
{
	closing = atof (input.c_str());
}

//This function sets the Exchange number
void stockData::SetExchange()
{
	exchange = int (input.c_str());
}

//This function finds the change in the day's numbers
void stockData::SetChange()
{
	std::ostringstream sstream;
	double unchanged;

	unchanged = ((closing - opening) / opening) * 100;

	sstream << fixed << setprecision(2) <<unchanged << "%";
	change = sstream.str();
}


//This function outputs data
void stockData::output()
{
	cout << "Company ticker: " << ticker << endl;
	cout << "Date: " << convertedDate << endl;
	cout << "Opening Price: $" << opening << endl;
	cout << "Daily High Price: $" << high << endl;
	cout << "Daily Low Price: $" << low << endl;
	cout << "Closing Price: $" << closing << endl;
	cout << "Shares Exchanged: " << exchange << endl;
	cout << "Daily change: " << change << endl << endl;

}



// Overloaded less-than operator
bool stockData::operator< (stockData operL)
{
	bool compare = false;

	if (date < operL.date && ticker < operL.ticker)
		compare = true;
	else if (date > operL.date && ticker > operL.ticker)
		compare = false;
	else if (date == operL.date)
	{
		if (ticker < operL.ticker)
			compare = true;
		else
			compare = false;
	}

	return compare;
}







// Overloaded equal-to operator
bool stockData::operator== (stockData operE)
{
	bool compare = false;

	if (date == operE.date && ticker == operE.ticker)
		compare = true;
	else
		compare = false;

	return compare;
}

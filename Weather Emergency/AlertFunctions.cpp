// These functions store info one warning/alert
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

#include "AlertHeader.h"
#include "StringTokenizer.h"


//Decodes a coded alert message
string alert::decode(string weatherData)
{
	StringTokenizer decoder(weatherData);

	startT = decoder.getStringToken();
	endT = decoder.getStringToken();
	FIPS = decoder.getStringToken(); 
	type = decoder.getStringToken();  

	FIPS.replace(2,1,",");

	StringTokenizer decoderStart(startT, 'T');
	startD = decoderStart.getStringToken();
	startT = decoderStart.getStringToken();

	StringTokenizer decoderEnd(endT,'T');
	endD = decoderEnd.getStringToken();  
	endT = decoderEnd.getStringToken();  

	return FIPS;
}

//This function produces a more readable time
string alert::timeConvert(string oldTime)
{
	string hour;
	string minute;
	string time;

	StringTokenizer decoder(oldTime, ':');
	hour = decoder.getStringToken();
	minute = decoder.getStringToken();

	if(hour == "00")
	{
		hour = "12";
		time = hour + ":" + minute + " a.m.";
	}
	else if(hour == "01")
	{
		hour = "1";
		time = hour + ":" + minute + " a.m.";
	}
	else if(hour == "02")
	{
		hour = "2";
		time = hour + ":" + minute + " a.m.";
	}
	else if(hour == "03")
	{
		hour = "3";
		time = hour + ":" + minute + " a.m.";
	}
	else if(hour == "04")
	{
		hour = "4";
		time = hour + ":" + minute + " a.m.";
	}
	else if(hour == "05")
	{
		hour = "5";
		time = hour + ":" + minute + " a.m.";
	}
	else if(hour == "06")
	{
		hour = "6";
		time = hour + ":" + minute + " a.m.";
	}
	else if(hour == "07")
	{
		hour = "7";
		time = hour + ":" + minute + " a.m.";
	}
	else if(hour == "08")
	{
		hour = "8";
		time = hour + ":" + minute + " a.m.";
	}
	else if(hour == "09")
	{
		hour = "9";
		time = hour + ":" + minute + " a.m.";
	}
	else if(hour == "10")
	{
		hour = "10";
		time = hour + ":" + minute + " a.m.";
	}
	else if(hour == "11")
	{
		hour = "11";
		time = hour + ":" + minute + " a.m.";
	}
	else if(hour == "12")
	{
		hour = "12";
		time = hour + ":" + minute + " a.m.";
	}
	else if(hour == "13")
	{
		hour = "1";
		time = hour + ":" + minute + " p.m.";
	}
	else if(hour == "14")
	{
		hour = "2";
		time = hour + ":" + minute + " p.m.";
	}
	else if(hour == "15")
	{
		hour = "3";
		time = hour + ":" + minute + " p.m.";
	}
	else if(hour == "16")
	{
		hour = "4";
		time = hour + ":" + minute + " p.m.";
	}
	else if(hour == "17")
	{
		hour = "5";
		time = hour + ":" + minute + " p.m.";
	}
	else if(hour == "18")
	{
		hour = "6";
		time = hour + ":" + minute + " p.m.";
	}
	else if(hour == "19")
	{
		hour = "7";
		time = hour + ":" + minute + " p.m.";
	}
	else if(hour == "20")
	{
		hour = "8";
		time = hour + ":" + minute + " p.m.";
	}
	else if(hour == "21")
	{
		hour = "9";
		time = hour + ":" + minute + " p.m.";
	}
	else if(hour == "22")
	{
		hour = "10";
		time = hour + ":" + minute + " p.m.";
	}
	else if(hour == "23")
	{
		hour = "11";
		time = hour + ":" + minute + " p.m.";
	}

	return time;
}

//This function produces a more readable date
string alert::dateConvert(string oldDate)
{
	string year;
	string day;
	string month;
	string date;

	StringTokenizer decoder(oldDate, '-');
	year = decoder.getStringToken();
	month = decoder.getStringToken();
	day = decoder.getStringToken(); 

	if(month == "01")
	 {
		month = "JAN";
	 }
	 else if(month == "02")
	 {
		month = "FEB";
	 }
     else if(month == "03")
	 {
		month = "MAR";
	 }
     else if(month == "04")
	 {
		month = "APR";
	 }
     else if(month == "05")
	 {
		month = "MAY";
	 }
     else if(month == "06")
	 {
		month = "JUN";
	 }
     else if(month == "07")
	 {
		month = "JUL";
	 }
     else if(month == "08")
	 {
		month = "AUG";
	 }
     else if(month == "09")
	 {
		month = "SEP";
	 }
     else if(month == "10")
	 {
		month = "OCT";
	 }
     else if(month == "11")
	 {
		month = "NOV";
	 }
     else if(month == "12")
	 {
		month = "DEC";
	 }

	year = year.substr(2,2);

	date = day + " " + month + " " + year;

	return date;
}

//This function produces a readable warning message
void alert::warning(string county, string state)
{
	startT = timeConvert(startT);
	endT = timeConvert(endT);
	startD = dateConvert(startD);
	endD = dateConvert(endD);

	cout << type + " for " + county + " County, " + state << endl;
	cout << "Effective: " + startD + " at " + startT +
		" until " + endD + " at " + endT << endl << endl;
}
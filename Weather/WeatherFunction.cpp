//This file includes implementations for functions of the general
// weather class
//File:  WeatherFunction.cpp (implementing member functions)

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <math.h>
#include <stdlib.h>

using namespace std;

#include "WeatherHeader.h"


//Set data variables for michigan object
void weather::setAttributes(string rawData)
{
	string comma (",");
	int found;
	int found2;
	
	//sibstrings location from given line
	found = rawData.find(comma);
	location = rawData.substr (found-3, found);

	//substrings date from given line
	found = rawData.find(comma);
	date = rawData.substr (found+1, 10);

	//substrings temperature from given line
	found = rawData.find(comma, 5);
	temperature = rawData.substr (found+1, 2);

	//substring dew point from given line
	found = rawData.find(comma, 15);
	dew = rawData.substr (found+1, 2);

	//substring wind direction from given line
	found = rawData.find(comma, 19);
	found2 = rawData.find(comma, 21);
	direction = rawData.substr (found+1, found2-1 - found);

	//substring wind speed from given line
	found = rawData.find(comma, 22);
	found2 = rawData.find(comma, 24);
	speed = rawData.substr (found+1, found2-1 - found);

	//substring mercury numbers from given line
	found = rawData.rfind (comma);
	mercury = rawData.substr (found-4, 4);

	//substring condition code from given line
	found = rawData.rfind (comma);
	condition = rawData.substr (found+1);

}

//Convert Location code into outputable City name
void weather::giveLocation()
{
	string city;

	if(location == "AMN")
		city = "Alma";
	 else if(location == "BAX")
		city = "Bad Axe";
     else if(location == "MBS")
		 city = "Saginaw";
     else if(location == "FNT")
		 city = "Flint";
     else if(location == "LAN")
		 city = "Lansing";
     else if(location == "MOP")
		 city = "Mount Pleasant";

	 location = "in " + city + ", ";
}

//Convert Date code into outputable Date and Time
void weather::giveDate()
{
	string month;
	string day;
	string year;
	string time;

	//substrings month from date and converts it into word form
	month = date.substr (4, 2);

	 if(month == "01")
		month = "January";
	 else if(month == "02")
		month = "February";
     else if(month == "03")
		 month = "March";
     else if(month == "04")
		 month = "April";
     else if(month == "05")
		 month = "May";
     else if(month == "06")
		 month = "June";
     else if(month == "07")
		 month = "July";
     else if(month == "08")
		 month = "August";
     else if(month == "09")
		 month = "September";
     else if(month == "10")
		 month = "October";
     else if(month == "11")
		 month = "November";
     else if(month == "12")
		 month = "December";

	 //substrings day from date
	 day = date.substr (6, 2);

	 //substrings year from date and converts it to yyyy format
	 year = date.substr (0, 4);

	 //substrings time from date and converts it to t:tt format
	 time = date.substr (8);

	 if (time == "00")
		 time = "12am";
	 else if(time == "01")
		 time = "1am";
	 else if(time == "02")
		 time = "2am";
     else if(time == "03")
		 time = "3am";
     else if(time == "04")
		 time = "4am";
     else if(time == "05")
		 time = "5am";
     else if(time == "06")
		 time = "6am";
     else if(time == "07")
		 time = "7am";
     else if(time == "08")
		 time = "8am";
     else if(time == "09")
		 time = "9am";
     else if(time == "10")
		 time = "10am";
     else if(time == "11")
		 time = "11am";
     else if(time == "12")
		 time = "12pm";
	 else if(time == "13")
		 time = "1pm";
	 else if(time == "14")
		 time = "2pm";
     else if(time == "15")
		 time = "3pm";
     else if(time == "16")
		 time = "4pm";
     else if(time == "17")
		 time = "5pm";
     else if(time == "18")
		 time = "6pm";
     else if(month == "19")
		 time = "7pm";
     else if(time == "20")
		 time = "8pm";
     else if(time == "21")
		 time = "9pm";
     else if(time == "22")
		 time = "10pm";
     else if(time == "23")
		 time = "11pm";

	 //appends the changed month, day, and year into a single string
	date = "On " + month + " " + day + ", " + year + " at " + time + " ";
}

//Calculate Temperature in outputable Celsius as well as Fahrenheit
int weather::calcTemp()
{
	int temp, celsius;
	string fahr;
	string cels;
	char buffer[3];

	temp = atoi(temperature.c_str());

	celsius = (temp - 32) * (5 / 9 + .5) + .5;
	fahr = itoa (temp, buffer, 10);

	temperature = "the temperature is " + fahr + " degrees Fahrenheit (";

	return celsius;

}

//Convert Dew Point into outputable text
void weather::giveDew()
{
	dew = "the Dew Point is " + dew + " degrees fahrenheit, ";
}

//Convert Direction code into outputable text
void weather::giveDirect()
{
	if(direction == "N")
		direction = "north";
	 else if(direction == "NE")
		direction = "northeast";
     else if(direction == "E")
		 direction = "northeast";
     else if(direction == "SE")
		 direction = "southeast";
     else if(direction == "S")
		 direction = "south";
     else if(direction == "SW")
		 direction = "southwest";
     else if(direction == "W")
		 direction = "west";
     else if(direction == "NW")
		 direction = "northwest";
 
	 direction = "winds are from the " + direction;
}

//Convert Speed into outputable text
void weather::giveSpeed()
{
	speed = " at " + speed + " miles per hour, ";
}

//Calculate Mercury code into outputable measurement
void weather::calcMerc()
{
	string temp1;
	string temp2;

	temp1 = mercury.substr (0, 2);
	temp2 = mercury.substr (2, 2);
	mercury = "pressure is " + temp1 + "." + temp2 + " inches of mercury, ";
}

//Convert Condition code into outputable text
void weather::giveCond()
{
	if(condition == "CLD")
		condition = "skies are cloudy";
	 else if(condition == "CLR")
		condition = "skies are clear";
     else if(condition == "S")
		 condition = "it is snowing";
     else if(condition == "T")
		 condition = "a thunderstorm is reported";
     else if(condition == "PC")
		 condition = "skies are partly cloudy";
     else if(condition == "R")
		 condition = "it is raining";
     else if(condition == "DR")
		 condition = "drizzle is reported";
     else if(condition == "F")
		 condition = "conditions are foggy";
 
	 condition = "and " + condition;
}

//Output converted string data to console
void weather::giveOutput(int celsius)
{
	cout << date << location << endl << temperature << celsius << " degrees Celsius), " << endl << dew << endl
		<< direction << speed << endl << mercury << condition << endl << endl;
}

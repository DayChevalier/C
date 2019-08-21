// This file includes implementations for functions of the check
// writing class.

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

#include "CheckingHeader.h"


//Infiling the data
void checkWrite::setAttributes(int num, string first, string last, string dating, double cash)
{
	number = num;
	name = first + " " + last;
	amount = cash;
	date = dating;
	
}

//Display amount in word form
void checkWrite::convertAmount()
{
string ones[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
string teens[10] = {"TEN", "ELEVEN", "TWELVE", "THIRTEEN", "FOURTEEN", "FIFTEEN", "SIXTEEN", "SEVENTEEN", "EIGHTEEN", "NINETEEN"};
string tens[10] = {"zero", "zero", "TWENTY", "THIRTY", "FOURTY", "FIFTY", "SIXTY", "SEVENTY", "EIGHTY", "NINTEY"};
amountWorded = "";
std::stringstream stringPart;
int index = 0;
int first, second, third;
double part, whole;

//Breaking the amount's whole numbers from it's decimal
part = modf (amount, &whole);
	
//Breaking the total amount into its individual digits.
while (whole > 0 && index < 3)
{
	if (index = 1)
	{
		first = (int) whole % 10;	
		whole = (int) whole / 10;
	}
	if (index = 2)
	{
		second = (int) whole % 10;
		whole = (int) whole / 10;
	}
	if (index = 3)
	{
		third = (int) whole % 10;
		whole = (int) whole / 10;
	}
	index++;
}

//Changing the decimal to a whole number
part = part * 100;

//Outputing the individual numbers in word form
if (third > 0)
	amountWorded += ones[third] + " HUNDRED ";

if (second == 1)
	amountWorded += teens[first];
else if (second > 1)
{
	amountWorded += tens[second];
		if (ones > 0)
			amountWorded += "-" + ones[first];
}
else if (second == 0)
{
	if (ones > 0)
		amountWorded += ones[first];
}

if (amountWorded == "")
	amountWorded += "ZERO";

stringPart << part;
amountWorded += " AND " + stringPart.str() + "/100 DOLLARS";

}

//Display date in mm dd, yyyy form
void checkWrite::convertDate()
{
	string slash ("/");
	string month;
	string day;
	string year;
	string newDate;
	int found;
	int found2;

	//find the individual slashes as markers
	found = date.find(slash);
	found2 = date.rfind(slash);

	//substrings day and month from date and converts it into word form
	month = date.substr (0, found);

	 if(month == "1")
	 {
		month = "January";
		day = date.substr (found+1, found2-2);
	 }
	 else if(month == "2")
	 {
		month = "February";
		day = date.substr (found+1, found2-2);
	 }
     else if(month == "3")
	 {
		month = "March";
		day = date.substr (found+1, found2-2);
	 }
     else if(month == "4")
	 {
		month = "April";
		day = date.substr (found+1, found2-2);
	 }
     else if(month == "5")
	 {
		month = "May";
		day = date.substr (found+1, found2-2);
	 }
     else if(month == "6")
	 {
		month = "June";
		day = date.substr (found+1, found2-2);
	 }
     else if(month == "7")
	 {
		month = "July";
		day = date.substr (found+1, found2-2);
	 }
     else if(month == "8")
	 {
		month = "August";
		day = date.substr (found+1, found2-2);
	 }
     else if(month == "9")
	 {
		month = "September";
		day = date.substr (found+1, found2-2);
	 }
     else if(month == "10")
	 {
		month = "October";
		day = date.substr (found+1, found2-3);
	 }
     else if(month == "11")
	 {
		month = "November";
		day = date.substr (found+1, found2-3);
	 }
     else if(month == "12")
	 {
		month = "December";
		day = date.substr (found+1, found2-3);
	 }

	 //substrings year from date and converts it to yyyy format
	 year = "20";
	 year += date.substr (found2+1);

	 //appends the changed month, day, and year into a single string
	 date = month;
	 date += " ";
	 date += day;
	 date += ", ";
	 date += year;
}

//Output checks in check form
void checkWrite::displayCheck()
{
	std::stringstream stringPart;
	string stringAmount;

	stringPart << amount;
	stringAmount = "$" + stringPart.str();

	cout << "---------------------------------------------------------" << endl;
	cout << number << setw(53) << date << endl;
	cout << "PAY TO THE ORDER OF: " << setw(15) << name << setw(21) << stringAmount << endl << endl;
	cout << amountWorded << endl;
	cout << setw(57)<< "Delta College" << endl;

}

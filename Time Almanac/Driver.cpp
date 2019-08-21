// Dayton Chevalier
// Program 1
// CST280-WIN110
// This program establishes a system that allows a user to perfrom various functions
// relevent to a time almanac.
// Driver code is based on adapted sundemo.cpp course material program

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

#include "datefun.h"
#include "sun.h"
 
struct locationInfo
{
   char city[3];
   double lati;
   double longi;
   char zone;
};


const int MAX_LIST_SIZE = 100;

// Local Function prototypes
void inputDate(int&, int&, bool&, string&);
void makeLocationList(locationInfo locationList[MAX_LIST_SIZE], int& listSize);
void buildTable(int, int, locationInfo locationList[], bool, int);
void buildCalendar(int, int, int);
int dayMonth(int, int);
double Deg_Rad(double);
bool LeapYr(int);

int main ()
{
    // Local variables
    int  mon, year;
	bool dstOn;									// For daylight savings time
	locationInfo locationList[MAX_LIST_SIZE];   // Main list of parts
	int listSize = 0;							// Size of parts list
	int index = 0;
	int position = -1;        // To record position of search value
    bool found = false;       // Flag to indicate if the value was found
	string code;


    inputDate(mon, year, dstOn, code);     // Get date and time zone from user
	makeLocationList(locationList, listSize);  // Read parts list from file

	while (index < listSize && !found)
    {
        if (locationList[index].city == code)   // If the value is found
        {
            found = true;            // Set the flag
			position = index;        // Record the value's subscript

        }
        index++;                     // Go to the next element
    }

 if (position >= 0)
    {
		buildTable(mon, year, locationList, dstOn, index);    // Create sunrise/sunset table
		buildCalendar(mon, year, index);    // Create monthly calendar table
    }
    else
       cout << "Airport not found." << endl << endl;

    return 0;
}




//----------------------------------------------------------------------
// This function reads a list of parts from a file and populates
// and array of part records 
//----------------------------------------------------------------------
void makeLocationList(locationInfo locationList[], int &listSize)
{
   // Declarations
   locationInfo aLocation;
   ifstream InFile ("cityinfo.txt");
    
   if ( InFile.fail() )             // Test for file existence
   {
      cout <<  "Problem opening file";
      exit(-1);
   }
	
   int i = 0;
   InFile >> aLocation.city;
   InFile >> aLocation.lati >> aLocation.longi >> aLocation.zone;
   while( !InFile.eof() && i < MAX_LIST_SIZE)
   {
      locationList[i] = aLocation;
      i++;
	  InFile >> aLocation.city;
	  InFile >> aLocation.lati >> aLocation.longi >> aLocation.zone;
   }
   listSize = i;     // Size of list is number of parts
   
   InFile.close();
}



/******************************************************************/
/*      This function prompts the user to input a month, year and */
/*  time zone.                                                    */
/******************************************************************/      
void inputDate(int& month, int& yr, bool& dstON, string& code)
{
    char DST_answer;

	cout << "Enter your month in number form: (1...12) ";
    cin >> month;
	if (month < 1 || month > 12)
	{
		cout << endl << "Invalid month." << endl << endl;
		exit(-1);
	}
	cout << endl << "Enter your year: (19xx or 20xx) ";
	cin	>> yr;
	if (yr < 1900)
	{
		cout << endl << "Invalid year." << endl << endl;
		exit(-1);
	}
	cout << endl << "Enter the 3 letter code of your airport: (Ex. MBS) ";
	cin >> code;
    cout << endl;                         // Blank line
        
    do                                    // Prompt user for daylight savings time
    {
        cout << "Daylight savings time active? (y or n) ";
        cin >> DST_answer;
        cout << endl;                          
    }
    while (!(DST_answer == 'y' || DST_answer == 'Y' 
          || DST_answer == 'n' || DST_answer == 'N'));

	if (DST_answer == 'y' || DST_answer == 'Y')
		dstON = true;
	else
		dstON = false;

    cout << endl;                         // Blank line
}



/****************************************************************/
/*  This function accepts a month/year and time zone code       */
/*  and builds a table of sunrise/set values to console output. */
/****************************************************************/
void buildTable(int mon, int year, locationInfo locationList[], bool dst, int index)
{
    cout.setf(ios::fixed, ios::floatfield);         // Set up doubling
    cout.setf(ios::right);                          //   output format
    cout.setf(ios::showpoint);                              

    int day, maxday;
	locationInfo aLocation;
    TextTime rise,set;
                
    maxday = DaysInMonth(mon,year);          // Get max days in month

	aLocation = locationList[index-1];

    // Title
    cout << endl << aLocation.city << " Sunrise/sunset for " << mon << "/" << year << endl << endl;
        
    // Headings
    cout << "    Day Sunrise Sunset" << endl;
       
    for (day = 1; day <= maxday; day++)
    {
        Sun_Rise_Set(aLocation.lati, aLocation.longi, mon, day, year, aLocation.zone, dst, rise, set);
        cout << setw(6) << day << "  " << rise << "  " << set << endl;
    }
}







/**********************************************************/
/*  This function accepts a month and year and builds     */
/*  a table of the month as a calendar to console output. */
/**********************************************************/
void buildCalendar(int mon, int year, int index)
{
	string month;
    cout.setf(ios::fixed, ios::floatfield);         // Set up doubling
    cout.setf(ios::right);                          //   output format
    cout.setf(ios::showpoint);                              

    int day = 1, maxday, daynum;
                
    maxday = DaysInMonth(mon,year);          // Get max days in month

	//Determining month name
 switch(mon)
    {
        case 1:     month = "January";	break;
        case 2:		month = "February"; break;
        case 3:		month = "March";	break;
        case 4:		month = "April";	break;
        case 5:     month = "May";		break;
		case 6:		month = "June";		break;
		case 7:		month = "July";		break;
		case 8:		month = "August";	break;
		case 9:		month = "September"; break;
		case 10:	month = "October";	break;
		case 11:	month = "November";	break;
		case 12:	month = "December"; break;
    };

    // Title
	cout << endl << "Calendar for: " << month << " " << year << endl;

	// Finding the first day of the month
	daynum = weekDay(mon, day, year);
	

	// Creating the table
	for (int k=0; k < daynum; k++)
		cout << "     ";
	for (int i = 1; i <= maxday; i++)
	{
		cout << setw(5) << i;
		if ((i + daynum)%7 == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
}

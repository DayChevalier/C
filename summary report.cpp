//This program will take the information of Donators and ouput it in a user friendly mannor.
#include <iostream> 
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

const int MAX = 20;

//Prototypes
string dateChange(string inString);
string cityChange(string inString);
double donationChange(string inString, string &donation);
string namePull(string inString);
void outputData(string date, string city, string donation, double taxDeduct, string name);

int main()
{
	// string holders and such
	int i = 0;						//Index for Array
	string date;					//Current Donation Date
    string city;					//Current Donator's city
    string donation = "0";			//Current Donation Size
	double taxDeduct;				//Current Deductability
	string name;					//Current Donator Name
	string inString[MAX];				//Current String
	
	ifstream fileData ("donations.txt"); // Open file

    if (fileData.fail() )				// Test for file's existence
    {
      cout <<  "A problem occured trying to open the file";
      exit(-1);
    }

	 fileData >> inString[i];     // String reads
	
	 // Read and process file

      while( !fileData.eof() && i <= MAX)
	  {
		 // Break string apart and returns pieces altered
		 date = dateChange(inString[i]);
		 city = cityChange(inString[i]);
		 taxDeduct = donationChange(inString[i], donation);
		 name = namePull(inString[i]);
		 
		 // Write output separate strings
		 outputData(date, city, donation, taxDeduct, name);

		 i++;
		 fileData >> inString[i];     // String reads
		
    }

	   system("pause");


	return 0;
}






// Used to substring the date from the given line and convert it into a mm dd, yyyy format
string dateChange(string inString)
{
	string comma (",");
	string slash ("/");
	string oldDate;
	string month;
	string day;
	string year;
	string newDate;
	int found;
	
	//substrings date from given line
	found = inString.find(comma);
	oldDate = inString.substr (0, found);

	//substrings month from date and converts it into word form
	found= oldDate.find(slash);
	month = oldDate.substr (0, found);

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
	 found= oldDate.rfind(slash);
	 day = oldDate.substr (found-2, found -3);

	 //substrings year from date and converts it to yyyy format
	 found= oldDate.rfind(slash);
	 year = "20";
	 year += oldDate.substr (found+1);

	 //appends the changed month, day, and year into a single string
	 newDate = month;
	 newDate += " ";
	 newDate += day;
	 newDate += ", ";
	 newDate += year;

    return newDate;
}







// A sadly complex module that accomplishes 3 tasks. Infiles an array for zips and towns. Substrings the zip from the given line.
// And then binary searches the array for a matching zip. The related town name is then passed back to main.
string cityChange(string inString)
{
	const int MAX = 1200; 

	string comma (",");
	string zip;
	string city;
	int found;
	int elements;
	string tempData;
	string zipArray[MAX];
	string cityArray[MAX];
	string score ("_");

	

	
	// This Section infiles an array for Zip and their Towns.

	//open file and test for file existance
	ifstream stateData ("zipMIcity.txt");

    if (stateData.fail() )
    {
      cout <<  "Problem opening file";
      exit(-1);
    }

	//infile array for zip and city, file contains additional data to be ingored
	  int i = 0;
    getline(stateData, tempData);        
    while (!stateData.eof() && i < MAX)        
    {
		found = tempData.find(" ");
		zipArray[i] = tempData.substr (0, found);

		found = tempData.rfind(" ");
		cityArray[i] = tempData.substr (found +1);
	   
       i++;
       getline(stateData, tempData);           
    }    
	 elements = i;
	 stateData.close();





	// This section takes the substringed zip and performs a search to compare it to the array.

	//substring zip from line passed in
	found = inString.find(comma);
	zip = inString.substr (found +1, 5);

	//binary search
	int first = 0;                 //first array element
    int last = elements - 1;       //last array element
    int middle;                    //mid point of search
    int position = -1;             //position of search value
    bool known = false;            //flag

    while (!known && first <= last)
    {
        middle = (first + last) / 2;     //calculate mid point
        if (zipArray[middle] == zip)      //if value is found at mid
        {
            known = true;
            position = middle;
        }
        else if (zipArray[middle] > zip)  //if value is in lower half
            last = middle - 1;
        else
            first = middle + 1;          //if value is in upper half
    }





	// This section removes the underscore from any two word cities.

	found = cityArray[position].find(score);
	if (found >= 0)
	{
		cityArray[position].replace(found, 1, " ");
		city = cityArray[position];
	}
	else
		city = cityArray[position];


	return city;
}






// This module finds the amount that can be tax deducted for the donation.
double donationChange(string inString, string &donation)
{
	string comma (",");
	double donate;
	int found;
	int found1;
	int found2;
	int foundDif;
	string temp;
	double deduction;

	//substrings date from given line
	found1 = inString.find(comma, 10);
	found2 = inString.rfind(comma);
	foundDif = found2 - found1;
	donation = inString.substr(found1+1, foundDif-1);
	
	//convert string donation into cstring, and then into double
	found = donation.find("$");
	temp = donation.substr(found+1);
	donate = atof ( temp.c_str() );

	//calculate deductability on the donation
	deduction = donate * .8;


	return deduction;
}






// This module will pull the name out of the passed string.
string namePull(string inString)
{
	string comma (",");
	string name;
	int found = 0;

	//find name
	found = inString.rfind(comma);
	name = inString.substr(found+1);


	return name;
}






// This final void module will output all the data in a readable style.
void outputData(string date, string city, string donation, double taxDeduct, string name)
{
	string output;

	ostringstream temp; 

	temp <<  taxDeduct; 
	string value = temp.str();

	cout << "The " << name << " household from " << city << ", MI" << endl << "Donated "
		<< donation << " ($" + temp.str() << " tax-deductable) on " << date << endl << endl;
}

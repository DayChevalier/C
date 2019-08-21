//Weather class test driver
//This program demonstrates a various methods related to the 
// general weather class.
//Included:  setting variables, string convertion, data output

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

#include "WeatherHeader.h"

const int ARRAY_MAX = 10;

int main()
{     
    weather michigan[ARRAY_MAX];      //weather is the CLASS; michigan is the OBJECT    

	//Establish the index for array
	int i = 0;
	int celsius;
    string rawData;

	//Open file
	ifstream fileData ("weatherOb.txt");

	//Test for file's existence
    if (fileData.fail())
    {
      cout <<  "A problem occured trying to open the file";
      exit(-1);
    }

	//Input data
	fileData >> rawData;

    while( !fileData.eof() && i < ARRAY_MAX)
    {

    //Pull Data from file and set in object
	michigan[i].setAttributes(rawData);
    
	//Convert raw object Data into Location
	michigan[i].giveLocation();

	//Convet raw object Data into Date and Time
    michigan[i].giveDate();

	//Convert raw object Data into Temperature F. & C.
	celsius = michigan[i].calcTemp();

	//Convert raw object Data into Dew Piont
	michigan[i].giveDew();

	//Convert raw object Data into Wind Direction
	michigan[i].giveDirect();

	//Convert raw object Data into Wind Speed
	michigan[i].giveSpeed();

	//Convert raw object Data into Mercury Measurement
	michigan[i].calcMerc();

	//Convert raw object Data into Weather condition
	michigan[i].giveCond();
	
	//Output Converted object Data to Console
	michigan[i].giveOutput(celsius);

	//Add one to index
	i++;

	//Input data again
	fileData >> rawData;

	}

	system ("pause");

    return 0;
    
}  // end main function



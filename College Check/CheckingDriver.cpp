// This program infiles and then prints checks

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "CheckingHeader.h"

int main()
{     
	const int ARRAY_MAX = 20;

	//MusicList is the CLASS; play is the OBJECT
	checkWrite Delta[ARRAY_MAX];


	int record = 0;

	int number[ARRAY_MAX];
	string first[ARRAY_MAX];
	string last[ARRAY_MAX];
	string date[ARRAY_MAX];
	double amount[ARRAY_MAX];


	//Open file
	ifstream fileData ("checkdata.txt");

	//Test for file's existence
    if (fileData.fail())
    {
      cout <<  "A problem occured trying to open the file";
      exit(-1);
    }

	
	//Input data
	fileData >> number[record];

	fileData >> first[record];
	fileData >> last[record];
	fileData >> date[record];
	fileData >> amount[record];
	//Process Data
	Delta[record].setAttributes(number[record], first[record], last[record], date[record], amount[record]);
	Delta[record].convertAmount();
	Delta[record].convertDate();
	Delta[record].displayCheck();

	//Continue Processesing
    while( !fileData.eof() && record < ARRAY_MAX)
    {
	record++;
	number[record] = number[record-1] + 1;
	fileData >> first[record];
	fileData >> last[record];
	fileData >> date[record];
	fileData >> amount[record];

	Delta[record].setAttributes(number[record], first[record], last[record], date[record], amount[record]);
	Delta[record].convertAmount();
	Delta[record].convertDate();
	Delta[record].displayCheck();
	}


	return 0;
    
}  // end main function
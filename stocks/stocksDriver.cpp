//Dayton Chevalier
//CST 280
//This program is built to input stock name and date and output it's data for that day
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "stockInfoHeader.h"
#include "stockDataHeader.h"
#include "OrderLinkedList.h"
#include "BinTreeType.h"			

int main()
{
	string input;
	int x = 0;
	string code;
	string date;


	//have stockData input data one at a time. And have bintree organize multiple stock objects
	OrderLinkedList<stockInfo> orderedNames;


	ifstream inFile("ussyms.txt");

	if (inFile.fail())				// Test for file's existence
    {
      cout <<  "A problem occured trying to open the file" << endl;
      exit(-1);
    }

	while (!inFile.eof())
	{
		getline(inFile,input);
		stockInfo nameList(input);
		orderedNames.insertNode(nameList);  
	}
	inFile.close();




	//have stockData input data one at a time. And have bintree organize multiple stock objects
    BinTreeType<stockData> theTree;


	ifstream fileData("stocks200901.txt");

	if (fileData.fail())				// Test for file's existence
    {
      cout <<  "A problem occured trying to open the file" << endl;
      exit(-1);
    }
	

	while (!fileData.eof())
	{
		fileData >> input;
		stockData dataList(input);
		theTree.insertNode(dataList);          
	}
	fileData.close();



	cout << "Please enter the stock ticker code in all capitols: " << endl;
	cin >> code;

	cout << endl << "Please enter the formatted date in the form of yyyymmdd: " << endl;
	cin >> date;
	cout << endl;


	//search tree by code and date
	stockData searchCode(code, date);
	stockInfo searchName(code, date);

	//use data to find name in linked list
	if (orderedNames.searchList(searchName))
	{
		//output all data
		if (theTree.searchNode(searchCode))
		{
			searchName.output();
			searchCode.output();
		}
		else
			cout << "Date data not found." << endl << endl;
	}
	else
		cout << "Name not found." << endl << endl;


	return 0;
}
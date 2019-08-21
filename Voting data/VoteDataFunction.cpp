#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

#include "VoteDataHeader.h"


// This function initializes the array for the vote count
void voteData::SetAttributes()
{
	for (int i = 0; i < CANDIDATE; i++)
	{
	   for (int j = 0; j < PRECINCT; j++)
		   voteTable[i][j] = 0;
	}
}

// This function reads a sequential file of raw store sales data and
// builds a two-dimensional array containing the data
// File format:  {Candidate}{precinct}
void voteData::BuildGrid()
{
	string line, letter, number;
	int found, precinct, candidate;

	ifstream inFile ("votingdata.txt");

	inFile >> line;       // Priming read
	found = line.find(",");
	//substrings candidate from given line
	letter = line.substr (0, found);
	//substrings precinct from given line
	number = line.substr (found+1);

	//convert strings to int
	std::string myString = number;
	precinct = atoi(myString.c_str());

	if (letter == "A")
		candidate = 1;
	else if (letter == "B")
		candidate = 2;
	else if (letter == "C")
		candidate = 3;
	else if (letter == "D")
		candidate = 4;


	while (!inFile.eof() )
	{
		voteTable[candidate-1][precinct-1]++;  // Store sales amount; adjust C++ indexes
     	inFile >> line;       // continuation read
		found = line.find(",");
		//substrings candidate from given line
		letter = line.substr (0, found);
		//substrings precinct from given line
		number = line.substr (found+1);

		//convert strings to int
		std::string myString = number;
		precinct = atoi(myString.c_str());

		if (letter == "A")
			candidate = 1;
		else if (letter == "B")
			candidate = 2;
		else if (letter == "C")
			candidate = 3;
		else if (letter == "D")
			candidate = 4;
	}
}

// This function creates a summary report for the sales data including totals
// by Precinct and by Candidates
void voteData::SummarizeData()
{
   int tempTotal;

   cout << "Vote results" << endl;
   cout << "                   PRECINCT" << endl;
   cout << "CAND.   1      2      3      4      5      Total" << endl;
    
   for (int i = 0; i < CANDIDATE; i++)
   {
	   tempTotal = 0;
	   switch (i)
	   {
			case 0:
				cout << "A" << "    ";
				break;
			case 1:
				cout << "B" << "    ";
				break;
			case 2:
				cout << "C" << "    ";
				break;
			case 3:
				cout << "D" << "    ";
				break;
	   }

      for (int j = 0; j < PRECINCT; j++)
	  {
         cout << setw(5) << voteTable[i][j] << "  ";
		 tempTotal += voteTable[i][j];
	  }
	  cout << "    " << tempTotal;
      cout << endl;
   } 
   
   
   
   cout << "Total  ";
   for (int j = 0; j < PRECINCT; j++)
   {
	   tempTotal = 0;
	   for (int i = 0; i < CANDIDATE; i++)
	  {
		 tempTotal += voteTable[i][j];
	  }
	   cout << tempTotal << "   ";
   }
   cout << endl;

}
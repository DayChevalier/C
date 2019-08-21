// This program infiles and then prints voter data
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "VoteDataHeader.h"

int main()
{	  
	voteData election;
	election.SetAttributes();	//Prepares the array for its data
    election.BuildGrid();      // Load table of store data to array
    election.SummarizeData();  // Create totals and write report
    
    return 0;
}
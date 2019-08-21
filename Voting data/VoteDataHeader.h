// This file defines the specifications for a class to store
// attributes for a table of voter data.


class voteData
{
    private:                // PRIVATE data members
		static const int CANDIDATE = 4;
		static const int PRECINCT = 5;
		typedef int VoteGrid[CANDIDATE][PRECINCT];
		VoteGrid voteTable;       // Two-dimensional array to work with

        
    public:                 // PUBLIC member functions
        
		void SetAttributes();
		void BuildGrid();
		void SummarizeData();
};
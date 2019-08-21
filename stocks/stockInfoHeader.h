// This file defines the specifications for a class to store
// attributes for a stock ticker.

#include <string>
using namespace std;

class stockInfo
{
    private:                // PRIVATE data members
	
		string input;
		string ticker;
		string name;

        
    public:                 // PUBLIC member functions

        stockInfo();
		stockInfo(string data);
		stockInfo(string tickerInput, string dateInput);
		void getData(string data);
		void SetTicker();
		void SetName();
		void output();
		bool operator< (const stockInfo& operL);   // Overloaded less-than operator
		bool operator== (const stockInfo& operE);  // Overloaded equal-to operator

};
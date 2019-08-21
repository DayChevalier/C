// This file defines the specifications for a class to store
// attributes for a business stock.

#include <string>
using namespace std;

class stockData
{
    private:                // PRIVATE data members
		string input;
		string date;
		string convertedDate;
		string ticker;
		double opening;
		double high;
		double low;
		double closing;
		int exchange;
		string change;

        
    public:                 // PUBLIC member functions

        stockData();
		stockData(string Data);
		stockData(string tickerInput, string dateInput);
		void SetDate();
		void convertDate();
		void SetTicker();
		void SetOpening();
		void SetHigh();
		void SetLow();
		void SetClosing();
		void SetExchange();
		void SetChange();
		void output();
		bool operator< (stockData operL);   // Overloaded less-than operator
		bool operator== (stockData operE);  // Overloaded equal-to operator

};
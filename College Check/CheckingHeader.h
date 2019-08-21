// This file defines the specifications for a class to store
// attributes for a check list

class checkWrite
{
    private:                // PRIVATE data members

		int number;
		string name;
		string date;
		double amount;

		string amountWorded;
		string dateWorded;


        
    public:                 // PUBLIC member functions
        
		void setAttributes(int num, string first, string last, string dating, double cash);	//Setting the data
		void convertAmount();	//Convert cash amount style
		void convertDate();		//Convert date style
		void displayCheck();	//Display check
};
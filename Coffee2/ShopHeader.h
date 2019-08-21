// This file defines the specifications for a general shop class
// File:  ShopHeader.h (defining basic data members and member functions)

class Shop
{
    private:                // PRIVATE data members
        int coffee, latte, mocha;
        char customer;
        
    public:                 // PUBLIC member functions
		void setAttributes(int c, int l, int m, char cst);
		double calcTotal();
        double calcTax();
		double calcBulkDiscount();
		double calcSpecialDiscount();
		double calcNet();
};
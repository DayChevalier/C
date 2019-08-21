// Shop class test driver
// This program demonstrates a various methods related to the 
// general shop class.
// Included:  setting variables, total calculation, discount functions

#include <iostream>
#include <iomanip>
using namespace std;

#include "ShopHeader.h"

int main()
{     
    Shop theShop;      // Rectangle is the CLASS; theRect is the OBJECT    
    
    int cof, lat, moch;	// Work variables within main  
	char cust;
	double total, tax, discount, net;    
    
    // Prompt user for customer data
    cout << "Please enter the number of coffees bought: ";
    cin >> cof;
	cout << endl;
    
	cout << "Please enter the number of lattes bought: ";
    cin >> lat;
	cout << endl;

	cout << "Please enter the number of mochas bought: ";
    cin >> moch;
	cout<< endl;

	cout << "Please enter the customer's code: ";
    cin >> cust;
	cout << endl;

	// Set data in the object
    theShop.setAttributes(cof, lat, moch, cust);
    
	// Calculate total and tax
    total = theShop.calcTotal();
    tax = theShop.calcTax();


	// Calculate bulk discount, special discount,
	// and total discount
    discount = theShop.calcBulkDiscount();
    discount += theShop.calcSpecialDiscount();


	//Data Output
	cout << endl << endl;
	cout << "Total Coffees: " << cof << endl;
	cout << "Total Lattes: " << lat << endl;
	cout << "Total Mochas: " << moch << endl;
	cout << "Total Cost: $" << setprecision (4) << total << endl;
	cout << "Total Discounts: $" << setprecision (4) << discount << endl;
	cout << "Tax: $" << tax << endl;
	cout << endl << endl;

	//Net Total Calculation and output
	net = theShop.calcNet();
	cout << "Net Total: $" << setprecision (4) << net << endl;
    
	system ("pause");

    return 0;
    
}  // end main function




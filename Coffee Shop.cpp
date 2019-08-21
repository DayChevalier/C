//This program calcutes coffee bills for a college coffee shop

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
		
		int coffee, latte, mocha; //The number of each kind of coffee bought
		char customer;			//The customer code	
		double total, tax, discount, net;		//Tax and total to be refered to later

		//Input of Data
		cout << "Please enter the number of Coffees bought. ";
		cin >> coffee;
		cout << endl << "Please enter the number of Lattes bought. ";
		cin >> latte;
		cout << endl << "Please enter the number of Mochas bought. ";
		cin >> mocha;
		cout << endl << "Please enter their Customer Code. ";
		cin >> customer;
		

		//Error Catching
		if (coffee <0 || latte < 0 || mocha < 0)
			cout << endl << "Error! Please enter a whole number. ";
		else if ('s' != customer && 'f' != customer)
			cout << endl << "Error! Please enter a Customer Code. ";
		else 
		{	
		//Tax calculation
			if (customer == 'f')
				tax = .06;
			else
				tax = 0;
		//Total Calculation
			total = (coffee * 1.35) + (latte * 3.15) + (mocha * 3.45);

		//Discount Calculation
			if (total > 75)
				discount = (total * .2);
			else if (total > 60 && total <= 75)
				discount = (total * .15);
			else if (total >= 40 && total <= 60)
				discount = (total * .1);
			else if (total >= 20 && total < 40)
				discount = (total * .05);
			else if (total < 20)
				discount = (total * .03);
			else
				cout << endl << "This is an error that shouldn't be possible!" << endl;

		//Special Discount Calculation
			if (coffee > 60)
				discount = discount + 5;
			if (latte > 40)
				discount = discount + 10;
			if (mocha  > 50)
				discount = discount + 15;

		//Data Output
			cout << endl << endl;
			cout << "Total Coffees: " << coffee << endl;
			cout << "Total Lattes: " << latte << endl;
			cout << "Total Mochas: " << mocha << endl;
			cout << "Total Cost: $" << setprecision (4) << total << endl;
			cout << "Total Discounts: $" << setprecision (4) << discount << endl;
			cout << "Tax: $" << tax << endl;
			cout << endl << endl;

		//Net Total Calculation and output
				net = total + (total * tax);
				net = net - discount;
			cout << "Net Total: $" << setprecision (4) << net << endl;
		}
		cout << endl << endl;
		system ("pause");
	return 0;
}
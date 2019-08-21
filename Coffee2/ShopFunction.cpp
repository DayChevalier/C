// This file includes implementations for functions of the general
// coffee shop class
// File:  ShopFunction.cpp (implementing member functions)

#include <iostream>
using namespace std;

#include "ShopHeader.h"


// Set data variables for ahop object
void Shop::setAttributes(int c, int l, int m, char cst)
{
    coffee = c;
    latte = l;
	mocha = m;
	customer = cst;

	// Error catching
	if (coffee <0 || latte < 0 || mocha < 0)
	{
		cout << endl << "Error! Please enter a whole number. ";

		exit(1);
	}
	else if ('s' != customer && 'f' != customer)
	{
		cout << endl << "Error! Please enter a proper Customer Code. ";

		exit(1);
	}
	
}

// Calculate the total of shop object given number of
// drinks currently stored
double Shop::calcTotal()
{
	double total;

	total = (coffee * 1.35) + (latte * 3.15) + (mocha * 3.45);
    return total; 
}


// Calculate tax of shop object given
// customer code currently stored
double Shop::calcTax()
{
	double tax; 

	if (customer == 'f')
		tax = .06;
	else
		tax = 0;

    return tax;
}


// Calculate bulk discount of shop object
// given total currently stored
double Shop::calcBulkDiscount()
{
	double discount;
	double total;

	total = calcTotal();

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
	
	return discount;
}


// Calculate special discount of shop object
// given total currently stored
double Shop::calcSpecialDiscount()
{
	double discount = 0;

	if (coffee > 60)
		discount += 5;
	if (latte > 40)
		discount += 10;
	if (mocha  > 50)
		discount += 15;

		return discount;
}


// Calculate net cost of shop object
// given data currently stored
double Shop::calcNet()
{
	double net;
	double total;
	double tax;
	double discount;

	total = calcTotal();
	tax = calcTax();
	discount = calcBulkDiscount() + calcSpecialDiscount();

	net = total + (total * tax);
	net -= discount;

	return net;
}
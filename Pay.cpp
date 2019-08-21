//This program calcutes gross pay for hourly and salary workers
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int ID;									//The Employee ID
	char type;								//The Employee Type
	int hours, over;						//Hours worked, total and over
	double pay, salary, gross, tax, net;	//Worker hourly pay rate, salary, gross pay, tax, and net pay
	
	const int weeks = 26;					//The number of 2 week pay periods there are in a year


	ifstream infile("payData.txt");
	
	
	//Beginning of visable output.
	cout << "Employee ID	Gross		Tax		Net" << endl;

	while (!infile.eof())
	{
		infile >> ID >> type;

	if (type != 's') //This strange use of code was the only way I could get it to ouput the 'H' gross pay for some reason.
	{
		infile >> hours;
		infile >> pay;

		if (hours > 40)
		{
			over = hours - 40;
			gross = (pay * 40) + (over * (pay * 1.5));
		}	
		else if (hours <= 40 && hours >= 0)
			gross = pay * hours;
		else
			//This error should be unreachable so long as the information in the text file is correct.
			cout << "Error: Unreal number of hours workd." << endl;
	}
	else if (type = 's')
	{
		infile >> salary;
		gross = salary / weeks;
	}
	else
		//This error should be unreachable so long as the information in the text file is correct.
		cout << "Error: Incorrect employee type" << endl;
	
	//if gross case statment. Used to determine tax.
	if (gross > 4100)
	{
		tax = gross * .4;
		net = gross - tax;
	}
	else if (gross > 2860 && gross <= 4100)
	{
		tax = 680.55 + ((gross - 2860) * .32);
		net = gross - tax;
	}
	else if (gross >= 925 && gross <= 2860)
	{
		tax = 138.75 + ((gross - 925) * .28);
		net = gross - tax;
	}
	else if (gross <= 925 && gross >= 0)
	{
		tax = (gross - .15);
		net = gross - tax;
	}
	else
		//This error should be unreachable so long as the information in the text file is correct.
		cout << "Error: Unreal gross pay" << endl;

	//Output Type, Gross, Tax, and Net.
	cout << type << "		" << gross << "		" << tax << "		" << net << endl;
	//This seems to create a double of the final line before ending.
	
	}
	infile.close();
	cout << endl << endl;
		system ("pause");
}
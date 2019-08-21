// This program calculates windchill temperature and then 
// advices the user of health risks
#include <iostream>
#include <math.h>
using namespace std;

// Function prototypes
void getInput(int& speed, int& temp);
double calcWindchill(int speed, int temp);
int calcTotal(double windchill);
void giveOutput(int total, int temp, int speed);
void giveAdivsory(int total);






int main ()
{
	int speed, temp, total;
	double windchill;
// Input
	getInput(speed, temp);

// Calculation function
	windchill = calcWindchill(speed, temp);

// Advisory function
	total = calcTotal(windchill);

// Output function
   giveOutput(total, temp, speed);

// Output Advisory
   giveAdivsory(total);

system ("pause");

    return 0;                
}






// This function reads the inputted speed
void getInput(int& speed, int& temp)
{

	//input speed and temp
	do {
    cout << "Please enter a reasonable windspeed." << endl;
	cin >> speed;
	do {
	cout << "Please enter a reasonable temperature." << endl;
	cin >> temp;
	} while (temp < -55 || temp > 55);
	} while (speed < 0 || speed > 65);
}





// This function calculates the winchill
double calcWindchill(int speed, int temp)
{
	double windchill;

	//Calculate Windchill from Speed and Temp
	windchill = 35.74 + (0.615 * temp) - (35.75 * (pow (speed, 0.16))) + (0.4275 * temp *(pow (speed, 0.16)));

	return (windchill);
}






// This function rounds the windchill
int calcTotal(double windchill)
{
	int total;
	double rounding;
	//Round Windchill into a whole number
	
	if (windchill >= 0)
	{
		rounding = windchill + 0.5;
		total = floor (rounding);
	}
	else
		rounding = windchill - 0.5;
		total = floor (rounding);

	return (total);
}






// This function sets up the output
void giveOutput(int total, int temp, int speed)
{
	//Output Data Text
	cout << "The current Temperature is: " << temp << " Degrees F." << endl;
	cout << "The current Wind Speed is: " << speed << " MPH" << endl;
	cout << "The current WindChill is: " << total << " Degress F." << endl;
}






// This function determines the Advisory to output
void giveAdivsory(int total)
{
	//Output Advisory Text
	if (total < -48)
		cout << "Life threatening: Frostbite can occur within 5 minutes." << endl;
	else if (total >= -48 && total <= -31)
		cout << "Danger: Frostbite can occur within 10 minutes." << endl;
	else if (total >= -30 && total <= -13)
		cout << "Warning: Frostbite can occur within 30 minutes." << endl;
	else if (total >= -12 && total <= 17)
		cout << "Advisory: Frostbite can occur with extended exposure." << endl;
	else if (total >= 18 && total <= 39)
		cout << "Notice: Where cold weather clothing as needed for comfort." << endl;
	else
		cout << "No significant cold weather risk." << endl;
}

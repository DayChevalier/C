//This program calcutes distance traveled in statute miles, average speed in mph, time spent in weeks and days, fuel in gallons, and its usage in mpg.

#include <iostream>
using namespace std;

int main()
{
		
		int time;
		float nautdistance, statdistance, speed, fuel, weeks, days, gallons, mpg;

		cout << "Please enter Time traveled in hours. ";
		cin >> time;
		cout << "Please enter Distance traveled in nautical miles. ";
		cin >> nautdistance;
		cout << "Please enter Fuel used in liters. ";
		cin >> fuel;

		statdistance = nautdistance * 1.15;
		speed = statdistance / time;
		weeks = time / (24 * 7);
		days = time / 24;
		gallons = fuel * 0.26417;
		mpg = statdistance / gallons;

		cout << endl << endl;
		cout << "TRIP SUMMARY" << endl;
		cout << "Distance: " << nautdistance << " Nautical Miles" << endl;
		cout << statdistance << " Statute Miles" << endl;
		cout << "Average speed: " << speed << " mph" << endl;
		cout << "Time: " << weeks << " weeks " << days << " days " << time << " hours" << endl;
		cout << "Fuel: " << gallons << " gallons used for " << mpg << " miles per gallon" << endl;

		cout << endl << endl;
		system ("pause");
	return 0;
}
// These functions recieve football player data and checks the height and gameplay record for all players 

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

#include "FootballHeader.h"

//Default constructor
Football::Football()
{
	time = 0.0;
}

//This function sets the player 40 yard dash time member
void Football::setTime(double playerTime)
{
	time = playerTime;
}


//This function gets the player 40 yard dash time member
double Football::getTime()
{
	return time;
}


//This function decides if the player is a candidate
void Football::isCandidate()
{
	if (candidate == true && height > 73 && weight > 190 && time < 4.7)
		cout << name << " for football" << endl;

}
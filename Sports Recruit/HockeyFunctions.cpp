// These functions recieve hockey player data and checks the height and gameplay record for all players 

#include <iostream>
#include <string>
using namespace std;

#include "HockeyHeader.h"

//Default constructor
Hockey::Hockey()
{
	goals = 0;
	penalties = 0;
	plusMinus = 0;
}

//This function sets the player goals per season member
void Hockey::setGoals(int playerGoals)
{
	goals = playerGoals;
}

//This function sets the player penalty minutes per game member
void Hockey::setPenalties(int playerPenalties)
{
	penalties = playerPenalties;
}

//This function sets the player plus-minus number member
void Hockey::setPlusMinus(int playerPlusMinus)
{
	plusMinus = playerPlusMinus;
}


//This function gets the player goals per season member
int Hockey::getGoals()
{
	return goals;
}

//This function gets the player penalty minutes per game member
int Hockey::getPenalties()
{
	return penalties;
}

//This function gets the player plus-minus number member
int Hockey::getPlusMinus()
{
	return plusMinus;
}


//This function decides if the player is a candidate
void Hockey::isCandidate()
{
	if (candidate == true && goals >= 15 && penalties < 12 && plusMinus > 15)
		cout << name << " for hockey" << endl;

}
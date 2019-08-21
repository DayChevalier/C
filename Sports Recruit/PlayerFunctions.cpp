// These functions recieve basic player data and checks the GPA for all players 

#include <iomanip>
#include <string>
using namespace std;

#include "PlayerHeader.h"

//Default constructor
Player::Player()
{
	name = "N/A";
	height = 0;
	weight = 0;
	gpa = 0.0;

	candidate = false;
}


//This function breaks the player data into pieces.
void Player::breakString(string playerData)
{
	string height;
	string weight;
	string gpa;
	int found;
	int found2;

	found = playerData.find(" ");
	found2 = playerData.find(" ", 2);
	setName(playerData.substr (found+1, found2-2));

	found = playerData.find(".");
	height = playerData.substr (found-8, found-7);
	setHeight(atoi(height.c_str()));

	weight = playerData.substr (found-5, found-2);
	setWeight(atoi(weight.c_str()));

	gpa = playerData.substr (found-1, found+3);
	setGPA(atof(gpa.c_str()));
	
}


//This function sets the player name member
void Player::setName(string playerName)
{
	name = playerName;
}

//This function sets the player height member
void Player::setHeight(int playerHeight)
{
	height = playerHeight;
}

//This function sets the player weight member
void Player::setWeight(int playerWeight)
{
	weight = playerWeight;
}

//This function sets the player GPA member
void Player::setGPA(double playerGPA)
{
	candidate = false;

	gpa = playerGPA;

	if (gpa > 2.3)
		candidate = true;
}



//This function gets the player name member
string Player::getName()
{
	return name;
}

//This function gets the player height member
int Player::getHeight()
{
	return height;
}

//This function gets the player weight member
int Player::getWeight()
{
	return height;
}

//This function gets the player GPA member
double Player::getGPA()
{
	return gpa;
}

//This function decides if the player is a candidate
void Player::isCandidate()
{
		candidate = true;
}
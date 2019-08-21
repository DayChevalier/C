// These functions recieve volleyball player data and checks the height and gameplay record for all players 

#include <iostream>
#include <string>
using namespace std;

#include "VolleyballHeader.h"

//Default constructor
Volleyball::Volleyball()
{
	aces = 0;
	kills = 0;
}

//This function sets the player aces member
void Volleyball::setAces(int playerAces)
{
	aces = playerAces;
}

//This function sets the player kills member
void Volleyball::setKills(int playerKills)
{
	kills = playerKills;
}



//This function gets the player service aces member
int Volleyball::getAces()
{
	return aces;
}

//This function gets the player kills member
int Volleyball::getKills()
{
	return kills;
}


//This function decides if the player is a candidate
void Volleyball::isCandidate()
{
	if (candidate == true && height >= 70 && aces >= 6 && kills >= 9)
		cout << name << " for volleyball" << endl;

}
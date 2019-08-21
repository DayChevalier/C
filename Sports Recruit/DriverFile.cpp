//This program is built to input weather data and output weather advisories.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

#include "FootballHeader.h"
#include "VolleyballHeader.h"
#include "HockeyHeader.h"

int main()
{	  
	Player basic;
	Football fPlayer;
	Volleyball vPlayer;
	Hockey hPlayer;

	const int MAX_ARRAY = 20;
	string playerData[MAX_ARRAY];
	string code;
	string time;
	string aces;
	string kills;
	string goals;
	string penalties;
	string plusMinus;
	int i = 0;

	ifstream inFile ("players.txt");

	if (inFile.fail() )				// Test for file's existence
    {
      cout <<  "A problem occured trying to open the file";
      exit(-1);
    }

	getline (inFile, playerData[i]);

	while (!inFile.eof() && i <= MAX_ARRAY)
	{
		int found;
	
		//substrings code from given line
		found = playerData[i].find(" ");
		code = playerData[i].substr (found-1, found);

		if (code == "F")
		{
			fPlayer.breakString(playerData[i]);

			found = playerData[i].find(".");
			time = playerData[i].substr (found+4, found+6);
			fPlayer.setTime(atof(time.c_str()));

			fPlayer.isCandidate();

		}
		else if (code == "V")
		{
			vPlayer.breakString(playerData[i]);

			found = playerData[i].find(".");
			aces = playerData[i].substr (found+6);
			vPlayer.setAces(atoi(aces.c_str()));

			kills = playerData[i].substr (found+9, found+10);
			vPlayer.setKills(atoi(kills.c_str()));

			vPlayer.isCandidate();

		}
		else if (code == "H")
		{
			hPlayer.breakString(playerData[i]);

			found = playerData[i].find(".");
			goals = playerData[i].substr (found+5, found+6);
			hPlayer.setGoals(atoi(goals.c_str()));

			penalties = playerData[i].substr (found+8, found+10);
			hPlayer.setPenalties(atoi(penalties.c_str()));

			plusMinus = playerData[i].substr (found+12, found+13);
			hPlayer.setPlusMinus(atoi(plusMinus.c_str()));

			hPlayer.isCandidate();

		}
		else
			cout << "This code is not valid.";
		
		i++;
		getline (inFile, playerData[i]);
	}

	inFile.close();

    return 0;
}
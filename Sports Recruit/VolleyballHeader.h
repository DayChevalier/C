// This file define a class to store information about
// a volleyball player

#include <string>
using namespace std;

#include "PlayerHeader.h"

class Volleyball : public Player
{
    private:                // PRIVATE data members
		int aces;
		int kills;

    public:                 // PUBLIC member functions
        Volleyball();
		void setAces(int playerAces);
		void setKills(int playerKills);
		int getAces();
		int getKills();
		void isCandidate();


};
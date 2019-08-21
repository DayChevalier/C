// This file define a class to store information about
// a hockey player

#include <string>
using namespace std;

#include "PlayerHeader.h"

class Hockey : public Player
{
    private:                // PRIVATE data members
		int goals;
		int penalties;
		int plusMinus;

    public:                 // PUBLIC member functions
        Hockey();
		void setGoals(int playerGoals);
		void setPenalties(int playerPenalties);
		void setPlusMinus(int playerPlusMinus);
		int getGoals();
		int getPenalties();
		int getPlusMinus();
		void isCandidate();


};
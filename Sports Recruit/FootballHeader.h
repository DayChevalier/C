// This file define a class to store information about
// a football player

#include <string>
using namespace std;

#include "PlayerHeader.h"

class Football : public Player
{
    private:                // PRIVATE data members
		double time;

    public:                 // PUBLIC member functions
        Football();
		void setTime(double playerTime);
		double getTime();
		void isCandidate();


};
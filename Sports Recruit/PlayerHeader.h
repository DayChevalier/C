#ifndef PLAYER_H
// This file defines the specifications for a class to store
// attributes for a list of base sports player data

#include <string>
using namespace std;

class Player
{
     protected:                // PRIVATE data members
		string name;
		int height;
		int weight;
		double gpa;
		bool candidate;

    public:                 // PUBLIC member functions
        Player();
		void breakString(string playerData);
		void setName(string playerName);
		void setHeight(int playerHeight);
		void setWeight(int playerWeight);
		void setGPA(double playerGPA);
		string getName();
		int getHeight();
		int getWeight();
		double getGPA();
		virtual void isCandidate();


};
#define PLAYER_H
#endif
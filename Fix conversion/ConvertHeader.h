// This file defines the specifications for a class to store
// attributes used in functions to change infix into postfix

#include <string>
using namespace std;

class FixChange
{
    private:                // PRIVATE data members
		string infix;
		string postfix;

    public:                 // PUBLIC member functions
        FixChange();
		void setInfix(string infixData);
		string getPostfix();
		void postfixConversion();
		int precedence(char oper);

};
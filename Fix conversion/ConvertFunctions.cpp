// These functions recieve infix data and converts it to postfix

#include <iostream>
#include <string>
using namespace std;

#include "ConvertHeader.h"
#include "StackType.h"

//Default constructor
FixChange::FixChange()
{
	infix = "";
	postfix = "";
}

//This function sets the infix string
void FixChange::setInfix(string infixData)
{
	infix = infixData;
}

//This function gets the infix string
string FixChange::getPostfix()
{
	return postfix;
}


//This function converts infix to postfix
void FixChange::postfixConversion()
{
	StackType<char> charStack(20);

	const string operands = "ABCDE";
	const string operators = "+-*/";
	int found;
	string popped;
	
	postfix = "";

	int len = infix.length();

	for (int n = 0; n <= len; n++)
	{
		found = operands.find(infix[n]);
		if (found >= 0)
			postfix += infix[n];

		found = operators.find(infix[n]);

		if (found >= 0)
		{
			while (charStack.showTop() != '(' && precedence(charStack.showTop()) >= precedence(infix[n]) && charStack.isEmpty() == false)
			{
				popped = charStack.pop();
				postfix += popped;
			}
			charStack.push(infix[n]);
		}

		if (infix[n] == '(')
			charStack.push(infix[n]);

		if (infix[n] == ')')
		{
			while (charStack.showTop() != '(')
			{
				popped = charStack.pop();
				postfix += popped;
			}
			charStack.pop();
		}
	}

	while (charStack.isEmpty() == false)
	{
		popped = charStack.pop();
		postfix += popped;
	}

	charStack.clear();
}

//This function determines operator precedence
int FixChange::precedence(char oper)
{
	if (oper == '+' || oper == '-')
		return 1;
	if (oper == '*' || oper == '/')
		return 2;
}

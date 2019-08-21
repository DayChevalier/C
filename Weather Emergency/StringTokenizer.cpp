// Class to manage "tokenized" data (comma-separated files)

#include<iostream>
#include<string>
using namespace std;

#include "StringTokenizer.h"

// Constructor
// Receive line of comma-delimited data and set index of current
// token to zero
StringTokenizer::StringTokenizer(string line)
{
   theLine = line;
   currIndex = 0;
   delimiterChar = ',';     // Default delimiter is comma
}

// Parameterized constructor - accepts a character other than a comma
// as delimiter.
// Precondition: separator is a single character (non-space)
// Postcondtion: data string NOT initialized
StringTokenizer::StringTokenizer(char newDelimiter)
{
   currIndex = 0;
   delimiterChar = newDelimiter;    // Set delimiter to programmer choice
}

// Parameterized constructor - accepts an initial string to parse and
// a character other than a comma as delimiter.
// Precondition: separator is a single character (non-space)
StringTokenizer::StringTokenizer(string line, char newDelimiter)
{
   theLine = line;
   currIndex = 0;
   delimiterChar = newDelimiter;   // Set delimiter to programmer choice
}

// "Set" and "Get" functhions
void StringTokenizer::setLine(string line)
{
   theLine = line;
}

string StringTokenizer:: getLine()
{
   return theLine;
}

// Reset index of current token to zero
void StringTokenizer::reset()
{
   currIndex = 0;
}

// Return number of tokens in current string
int StringTokenizer::numberTokens()
{
   int lineLength = theLine.length();
   int count = 0;
     
   for (int i = 0; i < lineLength; i++)
      if (theLine.at(i) == delimiterChar)
         count++;
         
   return count + 1;    // Return number of tokens as number of commas + 1
}

// To observe if token pointer is at end of string
bool StringTokenizer::atEnd()
{
   if (currIndex == theLine.length())
      return true;
   else
      return false;
}

// Return next token as a string object
// Precondition: Token pointer is not at end of string
string StringTokenizer::getStringToken()
{
   return get_a_Token();
}

// Return next token as a character object
// Precondition: Token pointer is not at end of string
char StringTokenizer::getCharToken()
{
   string tempString;
   char outChar;
   
   tempString = get_a_Token();                
   outChar = tempString[0];                   // Extract one char from string
   
   return outChar;
}

// Return next token as a double value
// Precondition: Token pointer is not at end of string
double StringTokenizer::getDoubleToken()
{
   char tempCharArray[20];
   string tempString;
   double outValue;
   
   tempString = get_a_Token();

   strcpy(tempCharArray,tempString.data() );  // Convert string to char array
   outValue = atof(tempCharArray);            // Convert numerator to string
   return outValue;
}

// Returns an integer value being referenced
int StringTokenizer::getIntToken()
{
   char tempCharArray[20];
   string tempString;
   int outInt;
   
   tempString = get_a_Token();

   strcpy(tempCharArray,tempString.data() );  // Convert string to char array
   outInt = atof(tempCharArray);              // Convert numerator to string
   return outInt;
}    


// This utility function retrieves the next token and returns it to
// be correctly typed before the final return from the object function call
string StringTokenizer::get_a_Token()
{
   string outString;
   
   int newIndex = theLine.find(delimiterChar,currIndex);      
   
   if (newIndex >= 0)   // If not last token
   {
      outString = theLine.substr(currIndex,newIndex - currIndex);
      currIndex = newIndex + 1;        // Advance to position after next comma
   }
   else    // If last token
   {
      outString =  theLine.substr(currIndex,theLine.length() - currIndex);
      currIndex = newIndex + 1;        // Advance to position end
   }
      
   return outString;
}


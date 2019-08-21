// string::copy
#include <iostream>
#include <string>
using namespace std;

int main ()
{
  size_t length;
  char buffer[20];
  string str ("Test string...");
  length=str.copy(buffer,0,1);
  buffer[length]='\0';
  cout << "buffer contains: " << buffer << "\n";
  return 0;
}

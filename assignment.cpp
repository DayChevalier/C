// This program generates the Fibonacci sequence both
// iteratively and recursively

#include <iostream>
using namespace std;

int Fib1 (int n);
int Fib2 (int n);

int main()
{
    // Write terms 0...10 - Iteratively
    for (int i = 0; i <= 10; i++)
        cout << Fib1(i) << " ";
    cout << endl;
    
    // Write terms 0...10 - Recursively
    for (int i = 0; i <= 10; i++)
        cout << Fib2(i) << " ";
    cout << endl;
	
	int x;
	cin >>x;

    return 0;
}

// This function returns the term of the Fibonacci sequence based
// on the term sequence number received as a parameter
// Iterative Solution
int Fib1 (int n)
{        
	int term1, term2, newTerm = 0;
		if (n == 0)
			return 0;
		else if (n == 1)
			return 1;
		else 
		{
			term1 = 0;
			term2 = 1;
			for (int i = 2; i <= n; i++)
			{
				newTerm = term1 + term2;
				term1 = term2;
				term2 = newTerm;
			}
			return newTerm;
		}
	
	return 0;
}

// This function returns the term of the Fibonacci sequence based
// on the term sequence number received as a parameter
// Recursive Solution
int Fib2 (int n)
{   
	int newTerm;

	if (n == 0)
		return 0;
	else if (n == 1)
		return 1; 
	else
		return Fib2 (n-1) + Fib2 (n-2);

    return 0;
}
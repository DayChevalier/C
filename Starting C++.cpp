// -----Preprocessing headers if any-----
// #include <-library here->
#include <iostream> //Used for CIN and COUT streaming
#include <fstream> //Used for File streaming
#include <cmath> //Used for advance math streaming
using namespace std; //namespace for the use of variables

//Constants if any
// : const int CONSTANT_NAME = 000

// -----Function prototypes if any-----
// void functionName(int [],int &, int);
// double functionName(int [], int, int, double &);

int main()
{
    int simpleArray[MAX_LIST_SIZE];		// Array of list elements
    int variable1, variable2;			// Index of last list element, minimum of list elements, and maximum of list elements
	double variable3, variable4;		// Average of list elements and standard deviation

    getList(inList, listsize, MAX_LIST_SIZE);

    averageCalc(inList, listsize, MAX_LIST_SIZE, average);
	average = averageCalc(inList, listsize, MAX_LIST_SIZE, average);
    cout << "Average Score: " << average << endl;

    maxMin(inList, listsize, max, min);
    cout << "Maximum: " << max << endl << "Minimum: " << min << endl;

	deviate(inList, listsize, average, deviation);
	deviation = deviate(inList, listsize, average, deviation);
	cout << "Standard Deviation: " << deviation << endl;

	quart(inList, listsize);
    
	system ("pause");

    return 0;
}

/************************************************************/
/* This function opens a file to retrieve a list of integer */
/* values.  Values are stored in an array and passed to the */
/* calling routine.                                         */
/************************************************************/
void getList(int inList[],int& listsize,int maxlistsize)
{
   ifstream InFile ("pgm5data.txt");	// Open file
   int ListElement;
    
   int i = 0;
   InFile >> ListElement;
   while( !InFile.eof() && i < maxlistsize)
   {
      inList[i] = ListElement;
      i++;
      InFile >> ListElement;
   }
   listsize = i;     // Size of list is number of elements
}

/************************************************************/
/* This function receives the array and the size of the     */
/* list, and Averages it.                                   */
/************************************************************/
double averageCalc(int list[], int listsize, int maxlistsize, double& average)
{
	average = 0;
	for (int i = 0; i < listsize; i++)
	{
		average += list[i];
	}
	average = average / listsize;

	return (average);
}

/************************************************************/
/* This function receives the array and the size of the     */
/* list, and finds the maximum and minimum value in it.     */
/************************************************************/
void maxMin(int list[], int listsize, int& max, int& min)
{
	max = 0;
    min = 100;

	for (int i=0; i < listsize; i++)
		{
            if(list[i] > max)
			{
				max = list[i];
			}
			else if(list[i] < min)
			{
				min = list[i];
			}
		}
}

/************************************************************/
/* This function receives the array, the size of the list   */
/* and the average. It then deteremines standard deviation. */
/************************************************************/
double deviate(int list[], int listsize, double average, double& deviation)
{
	deviation = 0;
	for (int i = 0; i < listsize; i++)
	{
		deviation = deviation + pow((list[i] - average), 2);
	}
	deviation = sqrt(deviation/(listsize-1));

	return (deviation);
}

/************************************************************/
/* This function receives the array and the size of the list*/
/* which it then uses to plot frequency in quartiles.       */
/************************************************************/
void quart(int list[], int listsize)
{
	int quart1 = 0, quart2 = 0, quart3 = 0, quart4 = 0;

	for (int i = 0;i < listsize; i++)
	{
            if(list[i] >= 0 && list[i] < 25)
			{
				quart1 += 1;
			}
			else if(list[i] >= 25 && list[i] < 50)
			{
				quart2 += 1;
			}
			else if(list[i] >= 50 && list[i] < 75)
			{
				quart3 += 1;
			}
			else
			{
				quart4 += 1;
			}
		}

	cout << "Number of Scores in the Top Percentile: " << quart4 << endl;
	cout << "Number of Scores in the Third Percentile: " << quart3 << endl;
	cout << "Number of Scores in the Second Percentile: " << quart2 << endl;
	cout << "Number of Scores in the Bottom Percentile: " << quart1 << endl;
}
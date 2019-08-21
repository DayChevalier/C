#include <iostream> 
#include <fstream>
#include <iomanip>
using namespace std;

const int ARRAY_SIZE = 50;

void listOutput(int date[], int number[], int salary[], int choice);
void listAdd(int date[], int number[], int salary[]);
void listDelete(int date[], int number[], int salary[]);

int main()
{
	// Constants for menu choice
	const short MENU = 0, E_DATE = 1, E_NUMBER = 2, E_SALARY = 3, E_ADD = 4, E_DELETE = 5, EXIT = 6;
	int date[ARRAY_SIZE];		//Employee Date Array
    int number[ARRAY_SIZE];		//Employee Number Array
    int salary[ARRAY_SIZE];		//Employee Salary Array
	int choice;					// Menu choice
	
	fstream fileData;
	fileData.open("employeedata.txt"); // Open file


    if (fileData.fail() )				// Test for file's existence
    {
      cout <<  "A problem occured trying to open the file";
      exit(-1);
    }

	//Preset choice for Menu
	choice = 0;
	// Determine what function to use based on input choice
	while (choice != EXIT)
	{
		if (choice == MENU)
		{
		// Menu display
		cout << endl << "\t\tEmployee Data Management Menu" << endl
			 << endl << "1. List Employees by Hire Date."
			 << endl << "2. List Employees by employee number."
			 << endl << "3. Write total of Employee Salaries."
			 << endl << "4. Add an Employee."
			 << endl << "5. Delete an Employee."
			 << endl << "6. Exit Menu." << endl
			 << endl << "Please enter a number from the menu. ";
		cin >> choice;
		}
		else if (choice == E_DATE)
		{
			cout << endl;
			listOutput(date, number, salary, choice);
			cout << endl << "Enter another option from the menu. Press 0 to re-show the menu."
				 << endl << "Press 6 to exit the program. ";
			cin >> choice;
		}
		else if (choice == E_NUMBER)
		{
			cout << endl;
			listOutput(date, number, salary, choice);
			cout << endl << "Enter another option from the menu. Press 0 to re-show the menu."
				 << endl << "Press 6 to exit the program. ";
			cin >> choice;
		}
		else if (choice == E_SALARY)
		{
			cout << endl;
			listOutput(date, number, salary, choice);
			cout << endl << "Enter another option from the menu. Press 0 to re-show the menu."
				 << endl << "Press 6 to exit the program. ";
			cin >> choice;
		}
		else if (choice == E_ADD)
		{
			cout << endl;
			listAdd(date, number, salary);
			cout << endl << "Enter another option from the menu. Press 0 to re-show the menu."
				 << endl << "Press 6 to exit the program. ";
			cin >> choice;
		}
		else if (choice == E_DELETE)
		{
			cout << endl;
			listDelete(date, number, salary);
			cout << endl << "Enter another option from the menu. Press 0 to re-show the menu."
				 << endl << "Press 6 to exit the program. ";
			cin >> choice;
		}
		else
		{	
			cout << endl;
			cout << "That was not a valid option, please enter another option from the menu."
				 << endl << "Press 0 to re-show the menu. Press 6 to exit the program. ";
			cin >> choice;
		}
	}
	if (choice == EXIT)
		return 0;
}




  /****************************************************************************/
 /* This code displays the list sorted based on the user's choice*************/
/****************************************************************************/
void listOutput(int date[], int number[], int salary[], int choice)
{
// Input parallel records from file of unknown length
    int totalRecs = 0;    // Counter for total "records" of data
    int currRec = 0;      // Pointer to current data record
	int temp, end;		// Place holders for sorting
	ifstream fileData;
	fileData.open("employeedata.txt"); // Open file

    // Priming read
    fileData >> date[currRec] >> number[currRec] >> salary[currRec];
    while( !fileData.eof() && currRec < ARRAY_SIZE)
    {
		currRec++;			// Add one to pointer
        fileData >> date[currRec] >> number[currRec] >> salary[currRec];     // Subsequent reads
    }
    // Capture final index pointer as number of elements (one index past last good element)
    totalRecs = currRec;	
   
    // Write array contents in parallel fashion
	if (choice == 1)
	{
		for (end = totalRecs - 1; end >= 0; end--)
		{
			for (int i = 0; i < end; i++)
			{
				if (date[i] > date[i + 1])
				{
					 temp = date[i];
					 date[i] = date[i + 1];
					date[i + 1] = temp;

					 temp = number[i];
					 number[i] = number[i + 1];
					number[i + 1] = temp;

					 temp = salary[i];
					 salary[i] = salary[i + 1];
					salary[i + 1] = temp;
				 }
			}
		}
		for (int i = 0; i < totalRecs; i++)
        		cout << date[i] << " " << number[i] << " " << salary[i] << endl;
	}
	else if (choice == 2)
	{
		for (end = totalRecs - 1; end >= 0; end--)
		{
			for (int i = 0; i < end; i++)
			{
				if (number[i] > number[i + 1])
				{
					 temp = date[i];
					 date[i] = date[i + 1];
					date[i + 1] = temp;

					 temp = number[i];
					 number[i] = number[i + 1];
					number[i + 1] = temp;

					 temp = salary[i];
					 salary[i] = salary[i + 1];
					salary[i + 1] = temp;
				 }
			}
		}
		for (int i = 0; i < totalRecs; i++)
        		cout << number[i] << " " << date[i] << " " << salary[i] << endl;
	}
	else if (choice == 3)
	{
		for (end = totalRecs - 1; end >= 0; end--)
		{
			for (int i = 0; i < end; i++)
			{
				if (salary[i] > salary[i + 1])
				{
					 temp = date[i];
					 date[i] = date[i + 1];
					date[i + 1] = temp;

					 temp = number[i];
					 number[i] = number[i + 1];
					number[i + 1] = temp;

					 temp = salary[i];
					 salary[i] = salary[i + 1];
					salary[i + 1] = temp;
				 }
			}
		}
		for (int i = 0; i < totalRecs; i++)
        		cout << salary[i] << " " << number[i] << " " << date[i] << endl;
	}
}




   /****************************************************************************/
  /* This code appends the list starting from the very bottom.*****************/
 /* It asks for input and then adds it to the file.***************************/
/****************************************************************************/
void listAdd(int date[], int number[], int salary[])
{
    int tempDate = 0;    // Counter for total "records" of data
	int tempNumber = 0;    // Counter for total "records" of data
	int tempSalary = 0;    // Counter for total "records" of data
	fstream fileData;
	fileData.open("employeedata.txt", ios::app); // Open file

		//Prompt user to add employee
		cout << "Please enter Date hired in form of yyyymmdd." << endl;
		cin >> tempDate;
		fileData << tempDate << " ";

		cout << "Please enter the Employee's 3 digit Number." << endl;
		cin >> tempNumber;
		fileData << tempNumber << " ";

		cout << "Please enter the Employee's 5 digit Salary." << endl;
		cin >> tempSalary;
		fileData << tempSalary << endl;

}




  /****************************************************************************/
 /* This code is used to delete existing pieces of data from the file*********/
/****************************************************************************/
void listDelete(int date[], int number[], int salary[])
{
	// Input parallel records from file of unknown length
    int totalRecs = 0;    // Counter for total "records" of data
    int currRec = 0;      // Pointer to current data record
	int deleteChoice;
	fstream fileData;
	fileData.open("employeedata.txt"); // Open file

    // Takes Data from file
    fileData >> date[currRec] >> number[currRec] >> salary[currRec];
    while( !fileData.eof() && currRec < ARRAY_SIZE)
    {
		currRec++;			// Add one to pointer
        fileData >> date[currRec] >> number[currRec] >> salary[currRec];     // Subsequent reads
    }
    // Capture final index pointer as number of elements (one index past last good element)
    totalRecs = currRec;	
    
	fileData.close();


    // Write array contents in parallel fashion a presents the option of deletion
	for (int i = 0; i < totalRecs; i++)
		cout << i << " " << date[i] << " " << number[i] << " " << salary[i] << endl;

	cout << "Please enter the digit next to the employee you wish to delete. ";
	cin >> deleteChoice;


	 for (int i = deleteChoice; i < totalRecs; i++)
	 {
		date[deleteChoice] = date[deleteChoice+1];
		number[deleteChoice] = number[deleteChoice+1];
		salary[deleteChoice] = salary[deleteChoice+1];
		date[totalRecs-1] = 0;
		number[totalRecs-1] = 0;
		salary[totalRecs-1] = 0;
	 }

	 totalRecs--;

	// Rewrites editted date to file
	fileData.open("employeedata.txt");

	for (int i = 0; i < totalRecs; i++)
		fileData << " " << date[i] << " " << number[i] << " " << salary[i] << endl;
	fileData.close();

}
// This program calculates various parameters of a
// right triangle.

#include <iostream>
#include <string>
using namespace std;

#include "MusicHeader.h"

int main()
{     
	//MusicList is the CLASS; play is the OBJECT
	musicList play;
    
	// Declaration
	int choice;					// Menu choice

	//Preset choice for Menu
	choice = 0;
	// Determine what function to use based on input choice
	while (choice != 8)
	{
		switch (choice)
		{
			case 0:
				// Menu display
				cout << endl << "\t\tMusic Library Menu" << endl
					<< endl << "1. Load Music Library."
					<< endl << "2. List Songs by Title."
					<< endl << "3. List Songs by Artist."
					<< endl << "4. List Songs in Random Order."
					<< endl << "5. Add a Song to the Library."
					<< endl << "6. Delete a Song from the Library."
					<< endl << "7. Save Music Library."
					<< endl << "8. Exit." << endl
					<< endl << "Please enter a number from the menu. ";
				cin >> choice;
				break;
			case 1:
				cout << endl;
				//Infiling the data
				play.setAttributes();
				cout << "Your music library has been loaded." << endl;
				cout << endl << "Enter another option from the menu. Press 0 to re-show the menu."
						<< endl << "Press 8 to exit the program. ";
				cin >> choice;
				break;
			case 2:
				//Display music list by title
				cout << endl << "Your Music Library listed by Title..." << endl;
				play.displayTitle();
				cout << endl << "Enter another option from the menu. Press 0 to re-show the menu."
						<< endl << "Press 8 to exit the program. ";
				cin >> choice;
				break;
			case 3:
				//Display music list by artist
				cout << endl << "Your Music Library listed by Artist..." << endl;
				play.displayArtist();
				cout << endl << "Enter another option from the menu. Press 0 to re-show the menu."
						<< endl << "Press 8 to exit the program. ";
				cin >> choice;
				break;
			case 4:
				//Display music list randomly
				cout << endl << "Your Music Library listed Randomly..." << endl;
				play.displayRandom();
				cout << endl << "Enter another option from the menu. Press 0 to re-show the menu."
						<< endl << "Press 8 to exit the program. ";
				cin >> choice;
				break;
			case 5:
				//Add song to music list
				play.addSong();
				cout << endl << "Enter another option from the menu. Press 0 to re-show the menu."
						<< endl << "Press 8 to exit the program. ";
				cin >> choice;
				break;
			case 6:
				//Remove song from music list
				play.deleteSong();
				cout << endl << "Enter another option from the menu. Press 0 to re-show the menu."
						<< endl << "Press 8 to exit the program. ";
				cin >> choice;
				break;
			case 7:
				//Rewrite music list to file
				play.rewriteList();
				cout << endl << "Enter another option from the menu. Press 0 to re-show the menu."
						<< endl << "Press 8 to exit the program. ";
				cin >> choice;
				break;
			default:
				cout << endl;
				cout << "That was not a valid option, please enter another option from the menu."
					 << endl << "Press 0 to re-show the menu. Press 8 to exit the program. ";
				cin >> choice;
			}
	}

	if (choice == 8)
	{
		cout << endl << "Thank you! Come again soon!" << endl;
		return 0;
	}
    
}  // end main function
// This file includes implementations for functions of the right
// triangle class.

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <cstdlib>

using namespace std;

#include "MusicHeader.h"


//Infiling the data
void musicList::setAttributes()
{
	const int ARRAY_MAX = 10;
	int i = 0;

	//Open file
	ifstream fileData ("songlist.txt");

	//Test for file's existence
    if (fileData.fail())
    {
      cout <<  "A problem occured trying to open the file";
      exit(-1);
    }

	//Input data
	fileData >> list.title[i];
	fileData >> list.artist[i];
	fileData >> list.genre[i];
	fileData >> list.length[i];


    while( !fileData.eof() && i < ARRAY_MAX)
    {
		i++;
		fileData >> list.title[i];
		fileData >> list.artist[i];
		fileData >> list.genre[i];
		fileData >> list.length[i];
	}
	total = i;
}

//Display music list by title
void musicList::displayTitle()
{
	string temp;

    // Write array contents in parallel fashion
	for (int end = total - 1; end >= 0; end--)
	{
		for (int i = 0; i < end; i++)
		{
			if (list.title[i] > list.title[i + 1])
			{
				temp = list.title[i];
				list.title[i] = list.title[i + 1];
				list.title[i + 1] = temp;

				temp = list.artist[i];
				list.artist[i] = list.artist[i + 1];
				list.artist[i + 1] = temp;

				temp = list.genre[i];
				list.genre[i] = list.genre[i + 1];
				list.genre[i + 1] = temp;

				temp = list.length[i];
				list.length[i] = list.length[i + 1];
				list.length[i + 1] = temp;
			}
		}
	}
	for (int i = 0; i < total; i++)
		cout << list.title[i] << " " << list.artist[i] << " " << list.genre[i] << " " << list.length[i] << endl;

}

//Display music list by artist
void musicList::displayArtist()
{
	string temp;

    // Write array contents in parallel fashion
	for (int end = total - 1; end >= 0; end--)
	{
		for (int i = 0; i < end; i++)
		{
			if (list.artist[i] > list.artist[i + 1])
			{
				temp = list.artist[i];
				list.artist[i] = list.artist[i + 1];
				list.artist[i + 1] = temp;

				temp = list.title[i];
				list.title[i] = list.title[i + 1];
				list.title[i + 1] = temp;

				temp = list.genre[i];
				list.genre[i] = list.genre[i + 1];
				list.genre[i + 1] = temp;

				temp = list.length[i];
				list.length[i] = list.length[i + 1];
				list.length[i + 1] = temp;
			}
		}
	}
	for (int i = 0; i < total; i++)
		cout << list.artist[i] << " " << list.title[i] << " " << list.genre[i] << " " << list.length[i] << endl;
}

//Display music list randomly
void musicList::displayRandom()
{
	string temp;
	int num = 0;
	srand(time(NULL));  // initialize seed "randomly"
    
	for (int end = total - 1; end >= 0; end--)
	{
        //Shuffle elements by randomly exchanging each with one other
        for (int i = 0; i < (total - 1); i++)
		{
            int r = i + (rand() % (total - 1)); //Random remaining position
			if (list.artist[i] < list.artist[r])
			{
				temp = list.title[i];
				list.title[i] = list.title[r];
				list.title[r] = temp;

				temp = list.artist[i];
				list.artist[i] = list.artist[r];
				list.artist[r] = temp;

				temp = list.genre[i];
				list.genre[i] = list.genre[r];
				list.genre[r] = temp;

				temp = list.length[i];
				list.length[i] = list.length[r];
				list.length[r] = temp;
			}
		}
	}
	for (int i = 0; i < total; i++)
		cout << list.title[i] << " " << list.artist[i] << " " << list.genre[i] << " " << list.length[i] << endl;


}

//Add song to music list
void musicList::addSong()
{
	//Counter for total "records" of data
	string tempTitle;   
	string tempArtist;  
	string tempGenre;   
	string tempLength; 

	//Prompt user to add song
	cout << endl << "Please enter the song's Title. Be sure to include underscores in place of spaces." << endl;
	cin >> tempTitle;
	list.title[total] = tempTitle + " ";

	cout << endl << "Please enter the song's Artist." << endl;
	cin >> tempArtist;
	list.artist[total] = tempArtist + " ";

	cout << endl << "Please enter the song's Genre." << endl;
	cin >> tempGenre;
	list.genre[total] = tempGenre + " ";

	cout << endl << "Please enter the song's Length." << endl;
	cin >> tempLength;
	list.length[total] = tempLength + " ";

	total++;


}

//Remove song from music list
void musicList::deleteSong()
{
	int choice;

  // Write array contents in parallel fashion a presents the option of deletion
	for (int i = 0; i < total; i++)
		cout << endl << i << " " << list.title[i] << " " << list.artist[i] << " " << list.genre[i] << " " << list.length[i] << endl;

	cout << endl << "Please enter the digit next to the song you wish to delete. ";
	cin >> choice;


	 for (int i = choice; i < total; i++)
	 {
		list.title[i] = list.title[i+1];
		list.artist[i] = list.artist[i+1];
		list.genre[i] = list.genre[i+1];
		list.length[i] = list.length[i+1];
	 }

	 total--;
}

//Rewrite music list to file
void musicList::rewriteList()
{
	fstream fileData;
	// Rewrites editted date to file
	fileData.open("songlist.txt");

	for (int i = 0; i < total; i++)
		fileData << list.title[i] << " " << list.artist[i] << " " << list.genre[i] << " " << list.length[i] << endl;
	fileData.close();
}
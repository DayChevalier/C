// This file defines the specifications for a class to store
// attributes for a music list

class musicList
{
    private:                // PRIVATE data members

		struct info
		{
			string title[10];
			string artist[10];
			string genre[10];
			string length[10];
		};
		info list;
		int total;


        
    public:                 // PUBLIC member functions
        
		void setAttributes();	//Infiling the data
		void displayTitle();	//Display music list by title
        void displayArtist();	//Display music list by artist
		void displayRandom();	//Display music list randomly
		void addSong();			//Add song to music list
		void deleteSong();		//Remove song from music list
		void rewriteList();		//Rewrite music list to file
};
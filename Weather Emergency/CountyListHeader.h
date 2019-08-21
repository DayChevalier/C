// This file defines the specifications for a class to store
// attributes for a list of county data.


class countyList
{
    private:                // PRIVATE data members
		static const int MAX = 3500;
		string fipsData[MAX];
		int i;

    public:                 // PUBLIC member functions
        countyList();
		string search(string location);
		void output(string location, string &state, string &county);

};
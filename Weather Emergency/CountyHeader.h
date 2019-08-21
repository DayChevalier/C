// This file defines the specifications for a class to store
// attributes on county data.


class county
{
    private:                // PRIVATE data members
		string FIPS;			//For holding the current FIPS Code
		string countyName;			//For holding the current county
		string state;			//For holding the current state

    public:                 // PUBLIC member functions
        county();
		void setFipsCode(string fipsCode);
		void setCounty(string name);
		void setStateCode(string stateCode);
		string getFipsCode();
		string getCounty();
		string getStateCode();

};
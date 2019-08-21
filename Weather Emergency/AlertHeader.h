// This file defines the specifications for a class to store
// attributes on alert data.


class alert
{
    private:                // PRIVATE data members
		string FIPS;			//For holding the current FIPS Code
		string startT;			//For holding the warning start time
		string startD;			//For holding the warning start date
		string endT;			//For holding the warning end time
		string endD;			//For holding the warning end date
		string type;			//For holding the warning type

    public:                 // PUBLIC member functions
        string decode(string weatherData);
		string timeConvert(string oldTime);
		string dateConvert(string oldDate);
		void warning(string county, string state);


};
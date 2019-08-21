//This file defines the specifications for a general weather class
//File:  WeatherHeader.h (defining basic data members and member functions)

class weather
{
    private:                // PRIVATE data members
        string location;
		string date;
		string temperature;
		string dew;
		string direction;
		string speed;
		string mercury;
		string condition;
        
    public:                 // PUBLIC member functions
		void setAttributes(string rawData);
		void giveLocation();
        void giveDate();
		int calcTemp();
		void giveDew();
		void giveDirect();
		void giveSpeed();
		void calcMerc();
		void giveCond();
		void giveOutput(int celsius);
};
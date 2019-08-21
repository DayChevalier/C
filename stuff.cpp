//***************************************************************
// This program reads a U.S. zip code from the user, returns the
// city and state for the zip code and then calculates the direct
// distance from Delta College to the post office using zip
// code location references read from an external file
//***************************************************************

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const int MAX_ARRAY = 1200;          // Max number of zip code entries
const int DELTA_ZIP = 48710;          // Base zip code for Delta College
const double DELTA_LAT = 43.55660;    // Delta College latitude
const double DELTA_LON = -83.99430;   // Delta College longitude (neg. for N. Hemi.

typedef char StateType[3];            // Data type for state char. strings (max 2 char)
typedef char CityType[31];            // Data type for city char. strings (max 30 char)

void getData(ifstream& inFile, int zip[], double lat[], double lon[],
             StateType state[], CityType city[], int& numVals);
int binarySearch(int array[], int numelems, int value);
double GreatCircleDist(double la1, double lo1, double la2, double lo2);
double Deg_Rad(double angle);

int main()
{
    ifstream fileIn;    // Input file identifier               
    
    // Declare parallel arrays for zip code data
    int zip[MAX_ARRAY];           // Array for zip codes
    double latitude[MAX_ARRAY];   // Array for latitudes
    double longitude[MAX_ARRAY];  // Array for longitudes
    StateType state[MAX_ARRAY];   // Array for states
    CityType city[MAX_ARRAY];     // Array for cities

    double distance;              // Calculated distance from base zip to target
    int numElems;                 // Actual number of values in array 
                                  // (1 more than largest index)
    int index;                    // Search outcome
                                
                                
    int targetZip;              // Zip code of desired community                    

   
    
    // Read file and count values in array
    getData(fileIn,zip,latitude,longitude,state,city,numElems);

    // Prompt user for source zip code:
    cout << "Enter your target zip code: ";
    cin  >> targetZip;
   
    // Search for index of desired zip code and Delta's
    // zip code
    index = binarySearch(zip, numElems, targetZip);
    
    if (index >= 0)
    {
        // Calculate great circle distance from Delta to target post
        // office using index found with search.  Convert geographical
        // coordinates from degrees to radians for use in formula
        distance = GreatCircleDist(DELTA_LAT,DELTA_LON,
                                   latitude[index],longitude[index]);                                                     
        // Write output
        cout << endl << endl;
        cout << "Distance from Delta College to" << endl;
        cout << city[index] << ", " << state[index];
        cout << " (Zip Code: " << targetZip  << ")" <<endl;
        cout << "is " << distance << " miles" << endl << endl;
    }
    else
        cout << endl << "Error: Zip code not found" << endl << endl;

    // Close file
    fileIn.close();    
    
    return 0;                
}

//***************************************************************
// This function reads 3 sets of integers and 2 stringsfrom a file 
// and storesthe values in an array.  It returns the loaded arrays 
// and thenumber of elements in the array
// File format:  zip_code  latitude  longitude state cityName
//***************************************************************
void getData(ifstream& inFile, int zip[], double lat[], double lon[],
             StateType state[], CityType city[], int& numVals)
{
    int i = 0;
    
    inFile >> zip[i] >> lat[i] >> lon[i] >> state[i] >> city[i];          
    while (!inFile.eof() && i < MAX_ARRAY)        
    {
       i++;        
       inFile >> zip[i] >> lat[i] >> lon[i] >> state[i] >> city[i];          
    }            
    numVals = i;
}

//***************************************************************
// The binarySearch function performs a binary search on an   
// integer array. array, which has a maximum of numelems      
// elements, is searched for the number stored in value. If the
// number is found, its array subscript is returned. Otherwise,
// -1 is returned indicating the value was not in the array.  
//***************************************************************
int binarySearch(int array[], int numelems, int value)
{
    int first = 0,                 // First array element
        last = numelems - 1,       // Last array element
        middle,                    // Mid point of search
        position = -1;             // Position of search value
    bool found = false;            // Flag

    while (!found && first <= last)
    {
        middle = (first + last) / 2;     // Calculate mid point
        if (array[middle] == value)      // If value is found at mid
        {
            found = true;
            position = middle;
        }
        else if (array[middle] > value)  // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1;          // If value is in upper half
    }
    return position;
}

//***************************************************************
// This function receives two sets of geographical coordinates
// and returns the great circle distance betweent them.       
// Preconditions:                                             
//    Latitude/longitude values in radians                    
//    Value ranges:  -90.0 ² Latitudes ² 90.0                 
//             -180.0 ² Longitudes <= 180.0                   
// Postconditions:                                         
//    Coordinate parameters are unchanged                     
//    Return value (distance) in kilometers                   
//***************************************************************
double GreatCircleDist(double la1, double lo1, double la2, double lo2)
{
  const double RADIUS_EARTH = 3963.189; // in miles

  // Convert local variables to radians  
  la1 = Deg_Rad(la1);
  lo1 = Deg_Rad(lo1);
  la2 = Deg_Rad(la2);
  lo2 = Deg_Rad(lo2);
  return RADIUS_EARTH * acos( sin(la1) * sin(la2) 
                      + cos(la1) * cos(la2) * cos(lo2-lo1) );
}

//***************************************************************
// This function receives a value in degrees and returns the 
// equivalent angle in radians                               
//***************************************************************
double Deg_Rad(double angle)
{
   double const pi = 3.1415926;
   return angle * pi / 180.0;
}

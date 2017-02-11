//Just learning file I/O.

#include <iostream>
#include <fstream> // the header required for i/o to/from files!
#include <vector>
using namespace std;

//made this from observing the nature of the data from the file to be read
struct Reading
{
    int hour;
    double temperature;
};

//the main
int main()
{
    int h; // to take hour values
    double t; //to take temperature values
    string wthr; // filename
    cin >> wthr;

    ifstream ist{wthr}; //Important: made an object called "ist" of type "ifstream". initialized it with the name of the file to be opened
    if(!(ist))return -1; //if failed to open, return. used the object!

    vector<Reading> temp_hour_combo; //a vector to contain the type Reading
    while(ist >> h >> t)    //Important: use of the ">>" operator of ist object!
    {
        if(!(h<0||h>4))
        {
            temp_hour_combo.push_back(Reading{h,t});
        }
    }
    string fl;
    cin >> fl;
    ofstream ost{fl}; //making of ost object of type ofstream. the object is initialized by the filename to output to!
    if(!ost) return -2;

    for(int i =0; i<temp_hour_combo.size(); i++)
    {
        ost<<temp_hour_combo[i].hour<<", "<<temp_hour_combo[i].temperature<<"\n"; //Important: use of the ">>" operator of ost object!
    }
}

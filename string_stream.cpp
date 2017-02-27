#include <iostream>
#include <fstream>
#include <sstream> //header needed for string streams
#include <string>

using namespace std;

//istringstream uses a string as its source
//while ostringstream makes a string as its target
//istringstream operates on a given string
//while ostringstream creates a empty string followed by its initialization prior to writing anything to it.

double str_to_double(string);
void file_maker();

int main()
{
    double d1 = str_to_double("10.341");
    cout << d1 << endl;
    file_maker();
    return 0;
}

//demonstration of istringstream
double str_to_double(string s)
{
    double d;
    istringstream ist{s};
    ist >> d;
    if(!ist){cout <<"No double found.\n"; return -1;}
    return d;
}

//demonstration of ostringstream
//using this, i can make automatically named files!! :D
void file_maker()
{
    for(int n=1; n<4; n++)
    {
        ostringstream outstring;
        outstring << "myfile" << n <<".txt";
        ofstream ost{outstring.str()};
        ost << "this is file no. "<< n <<"\n";
    }
}

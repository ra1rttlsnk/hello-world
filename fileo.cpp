/********************************************************
this program will write to a file what i give input to it
*********************************************************/
//It does
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<string> take_input();
void file_out(vector<string>);
int main()
{
    file_out(take_input());
    cout<<"\n\nSuccess!";
    return 0;
}

vector<string> take_input()
{
    string inp;
    vector<string> in;
    cout<<"Please enter some strings\n\n";
    while(cin >> inp && inp != "xt")
    {
        in.push_back(inp);
    }

    return in;
}

void file_out(vector<string> x)
{
    string fname;
    cout<< "\nPlease enter the filename: ";
    cin >> fname;
    ofstream ost{fname};

    if(!ost) {cout<<"Could not open";return;}
    for(string a : x)
    {
        ost<< a << " ";
    }

    return;

}

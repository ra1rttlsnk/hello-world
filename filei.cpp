#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> container;
    string file_name;
    string a;

    cout<<"Enter the filename: ";
    cin >> file_name;
    ifstream ist{file_name};
    if(!ist)return -1;

    while(ist >> a)
    {
        container.push_back(a);
    }

    for(string a: container)
    {
        cout << a << " ";
    }

    return 0;
}

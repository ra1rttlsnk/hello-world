//first of all, it is important to think about the i/o streams as pipelines
//let's analyze the following code


#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//the kind of data we are expecting from a file
struct Quest
{
	string a;
	long int x;
};

//operator function definitions
ostream& operator<<(ostream&, Quest&);
istream& operator>>(istream&, Quest&);

int main()
{
	//created a input pipe named "ifs" and one end of the pipe is attached to the file named "nw"
	ifstream ifs{"nw"};
	if(!ifs) return -1;

	Quest blah;
	//here the istream is a input file stream or "ifstream"
	//we use our operator function as if it was used like, operator>>(ifs, blah)
	//think of it as if the operator >> is being told to carry out some extra operation specified in the function
	ifs >> blah;

	//here, the output stream is cout and blah is of type Quest
	//the rest is the same
	cout << blah;
	return 0;
}


//this function will take arguments called of type istream and Quest.
//we modify the istream operator >>
//how it is done is the main question here, so lets proceed
istream& operator>>(istream& is, Quest &q)
	//first we create an input stream "is", we can use it like cin. at the end we return it as the return type is an istream right?
{
	string s;
	long int g;
	is >> s >> g;

	q.a = s;
	q.x = g;

	return is;
}

ostream& operator<<(ostream& os, Quest &q)
{
	return os << endl << q.a << " "<< q.x << endl;
}

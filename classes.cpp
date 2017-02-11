#include <iostream>
using namespace std;

class Invalid{};
//this class that i will implement now, will contain the attributes and methods that a calendar can possess
class Date
{
	public:
	//default constructor
	Date();

	//the other one
	Date(int, int, int);
	
	bool isValid();
	
	private:
	int year=2001, month=1, day=1;
};

bool Date::isValid()
{
		//i am aware that the following logic is not the absolute one. but for learning purposes, that will make do :/
		return !((year < 0) || (month < 1 || month > 12) || (day > 30 || day < 1));
   }
Date::Date(int y, int m, int d)
:year{y},month{m},day{d}
{
	if(!(isValid())) throw Invalid{};
	cout << year
		<<endl
		<<month
		<<endl
		<<day
		<<endl;
}

Date::Date()
{
		cout << year
		<<endl
		<<month
		<<endl
		<<day
		<<endl;
}
int main()
{
	try{
		Date newdate{};	
	Date anotherdate{1995,4,0};
	return 0;
	}

	catch(Invalid){
		cerr<<"Error!";
	return -1;	
	}
}

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
int main()
{
	int holder[20][20];

	//creating the input stream object & initializing
	ifstream ist{"largest product in a grid"};
	if(!ist){ cout<<"\nCould not open file. Terminating..."; return -1;}

	for(int x, n =0, p= 0;ist >> x;)
	{
		holder[n][p] = x;
		p++;
		if(p > 19) { p = 0; n++; }

	}

	for(int n=0; n < 20; n++)
	{
		for(int p=0; p < 20; p++)
			printf("%-5d", holder[n][p]);
		cout << endl;
	}

	// The work to get the numbers from the file is concluded. We have the array now. What remains is manipulating the 
	// data at hand (holder).

	// A pattern has emerged.
	// If descent is along diagonal, both index numbers increments by one or column index decrements as row index increments. 
	// All increment and decrements are by one.

	//0 to 17 horizontally
	//0 to 17 vertically
	//the square will be 4x4
	//the square will have only its diagonal, the left side and its adjacent side
	//what i'll do with it is multiply the numbers along the two lines and the diagonal
	//My square will be put inside a nested loop
	//i'll have a variable outside the scope of the loop to keep track of the larger number at every square
	//i'll have an array or vector of 4 slots. a variable will contain the largest of them.
	//another variable will contain the largest of the previous square and after comparing that with the largest of the current square, the larger will occupy this variable.


	/*Ok, let's implement the square*/
	long int k = 0;
	for(int ver = 0; ver < 17; ver++ )
	{
		for(int hor = 0; hor < 17; hor++)
		{
			long int f = 0;
			long int container[4]={1,1,1,1};
			for(int i=0; i<4; i++)
			{
				container[0] *= holder[ver][hor+i];
				cout<< endl<<container[0];
				container[1] *= holder[ver+i][hor];
				container[2] *= holder[ver+i][hor+i];
				container[3] *= holder[ver+i][hor+3-i];
			}

			for(int i = 0; i<3; i++ )
			{
				if(container[i]<container[i+1])
					f = container[i+1];
				else f = container[i];
			}

			if(f>k)
				k=f;
		}
	}

	cout << "\n\nThe largest product is: "<< k;
	return 0;
}

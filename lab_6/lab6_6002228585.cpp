// Bryan Thiha 	
// 6002228585
// 03/23/20


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

void read_file()
{
	ifstream infile;

	int x, y;

	infile.open("input.txt");

	int input[10][3];

	infile >> y;

	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			
			infile >> x;
																	// Storing all numbers into array 
			input[i][j] = x;

			cout << input[i][j] << " "; 

		}
		cout << endl;

	}
	infile.close();

	cout << endl;

	int distance[10][10];

	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			distance[i][j] = sqrt(pow((input[i][1] - input[j][1]), 2) + pow((input[i][2] - input[j][2]), 2));

			cout << distance[i][j] << " ";
		}
		cout << endl ;
	}

	cout << endl;
}

/*void edges(int input[10][3])
{
	int distance[10][10];

	for(int i = 0; i < 10, i++)
	{
		for(int j = 0; j < 10; j++)
		{
			distance[i][j] = sqrt(pow((input[i][1] - input[j][1]), 2) + pow((input[i][2] - input[j][2]), 2));

			cout << distance[i][j] << " ";
		}
		cout << endl;
	}
}*/

int main()
{

	vector<int> my_vec(10);

	read_file();

		
}

/*

infile.getline(input, 10);

	ss << input;

	ss >> x;

	cout << x << endl;

	infile.getline(input, 10);

	ss << input;

	ss >> y;

	cout << y << endl;

for(int i = 0; i < 11; i++)
	{
		infile.getline(input, 10);

		ss << input;

		ss >> x[i];

		cout << x[i] << endl;
	}*/ 
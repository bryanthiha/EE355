// Bryan Thiha 	
// 6002228585
// 02/19/20


#include <iostream>
#include <fstream>

using namespace std;


class matrix
{

	public:
		int value[20][10];

		int linear_search(matrix Matrix)
		{
			int first_num = Matrix.value[0][0];

			for(int i = 0; i < 20; i++)											//Checking every index of both arrays
			{
				for(int j = 0; j < 10; j++)
				{
					if(Matrix.value[i][j] == first_num && (i != 0))
					{
						return i;
					}
				}
			}
		}

		
		void sort_row(matrix* M, int a)
		{
			int number = M->value[a][0];

			int count = 0;

			
				for(int j = 1; j < 10; j++)
				{
					if(M->value[a][j+1] < number) 
					{

						M->value[a][j] = M->value[a][j + 1];
						

						M->value[a][j+1] = number;
					}
				
				}
				
		}
};


int main()
{

	matrix array;
	int entry, z;

	ifstream infile;	
	infile.open("input.txt");


	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			
			infile >> entry;
																	// Storing all numbers into an array 
			array.value[i][j] = entry;

			//cout << array.value[i][j] << " ";
		}

		cout << endl;

	}

	infile.close();

	z = array.linear_search(array);

	cout << z << endl;

	for(int k = 0; k < 10; k++)
	{
		cout << array.value[z][k] << " ";
	}

	cout << endl;

	array.sort_row(&array, z);

	for(int k = 0; k < 10; k++)
	{
		cout << array.value[z][k] << " ";
	}
	cout << endl;
}

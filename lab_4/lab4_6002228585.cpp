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

		
		void sort_row(matrix* Matrix, int a)
		{
			int number;

			int count = 0;

			while(count < 7)
			{	
				number = Matrix->value[a][0];

				for(int j = 0; j < 9; j++)
				{
					if(Matrix->value[a][j+1] < number) 
					{

						Matrix->value[a][j] = Matrix->value[a][j+1];
						

						Matrix->value[a][j+1] = number;
					}

					number = Matrix->value[a][j+1];
				
				}
				count++;
			}
				
		}

		int binary_search(matrix Matrix, int a)
		{
			int first_num = Matrix.value[0][0];

			int low = 0;
			int high = 10;
			int mid;

			while(low <= high)
			{
				mid = (low + high)/2;

				if(Matrix.value[a][mid] > first_num)
				{
					high = mid - 1;
				}
				else if(Matrix.value[a][mid] < first_num)
				{
					low = mid + 1;
				}
				else
				{
					return mid;
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

			cout << array.value[i][j] << " ";
		}

		cout << endl;

	}

	infile.close();
	cout << endl;



	z = array.linear_search(array);

	cout << "First num found in row: " << z << endl;



	for(int k = 0; k < 10; k++)
	{

		cout << array.value[z][k] << " ";
	}

	cout << endl << endl;



	array.sort_row(&array, z);


	for(int k = 0; k < 10; k++)
	{

		cout << array.value[z][k] << " ";

	}
	cout << endl << endl;


	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			cout << array.value[i][j] << " ";
		}

		cout << endl;

	}

	cout << endl;

	int b = array.binary_search(array,z);

	cout << "Index from binary search: " << b << endl;
}



// 391 42 536 99 683 779 718 968 661 193

// 42 391 99 536 683 718 779 661 193 968

// 42 99 391 536 683 718 661 193 779 968

// 42 99 391 536 683 661 193 718 779 968

// 42 99 391 536 661 193 683 718 779 968
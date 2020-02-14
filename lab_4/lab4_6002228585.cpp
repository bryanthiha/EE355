// Bryan Thiha 	
// 6002228585
// 02/19/20


#include <iostream>
#include <fstream>

using namespace std;

class Number
{
	private:
		int value;

	public:
		int get_value()
		{
			return value;
		}

		void set_value(int a)
		{
			value = a;
		}

};

class matrix
{

	public:
		Number value[20][10];
		
		int linear_search(matrix Matrix)
		{
			int first_num;

			value[0][0].set_value(first_num);

			for(int i = 0; i < 20; i++)											//Checking every index of both arrays
			{
				for(int j = 0; j < 10; j++)
				{
					if(Matrix.value[i][j].get_value() == first_num)
					{
						return i;
					}
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
			array.value[i][j].set_value(entry);

			cout << array.value[i][j].get_value() << " ";
		}

		cout << endl;

	}

	infile.close();

	z = array.linear_search(array);

	cout << z << endl;
}

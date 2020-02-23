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
		int iteration_time;
		int binary_iterate;

		int linear_search(matrix Matrix)
		{
			int first_num = Matrix.value[0][0];

			iteration_time = 0;

			for(int i = 0; i < 20; i++)											//Checking every index of both arrays
			{
				for(int j = 0; j < 10; j++)
				{
					iteration_time++;

					if(Matrix.value[i][j] == first_num && (i != 0))
					{
						return i;
					}
				}
			}
		}

		int row_index(matrix Matrix)
		{
			int x = (linear_search(Matrix))/10;
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
			binary_iterate = 0;

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
				binary_iterate++;
			}
			
		}
		int iteration_count()
		{
			return iteration_time;
		}


		int binary_slice()
		{
			return binary_iterate;
		}

		
};


int main()
{

	matrix array;

	int entry, row_index, num_iterations;

	int binary_index, bin_iterate;
	

	ifstream infile;	
	infile.open("input.txt");


	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			
			infile >> entry;
																	// Storing all numbers into an array 
			array.value[i][j] = entry;

		}

	}

	infile.close();


	row_index = array.linear_search(array);

	cout << "First num found in row: " << row_index << endl;

	
	num_iterations = array.iteration_count();

	cout << num_iterations << endl;


	array.sort_row(&array, row_index);


	binary_index = array.binary_search(array,row_index);

	cout << "index from binary search: " << binary_index << endl;

	bin_iterate = array.binary_slice();

	cout << "interation time from binary search: " << bin_iterate << endl;



	ofstream outfile;	
	outfile.open("output.txt");

	outfile << "Iteration number of linear search for FirstNum: " << num_iterations << endl << endl;
	outfile << "The sorted row including the element FirstNum: ";

	for(int k = 0; k < 10; k++)
	{

		outfile << array.value[row_index][k] << " ";

	}

	outfile << endl << endl << "The index of FirstNum obtained from the binary search: " << binary_index << endl << endl;

	outfile << "The iteration time of using the binary search: " << bin_iterate;
	
	outfile.close();

}



// 391 42 536 99 683 779 718 968 661 193

// 42 391 99 536 683 718 779 661 193 968

// 42 99 391 536 683 718 661 193 779 968

// 42 99 391 536 683 661 193 718 779 968

// 42 99 391 536 661 193 683 718 779 968
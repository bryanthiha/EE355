// Bryan Thiha 	
// 6002228585
// 02/24/20


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


			for(int i = 0; i < 20; i++)											// Checking every index
			{
				for(int j = 0; j < 10; j++)
				{
					
					iteration_time++;

					if(Matrix.value[i][j] == first_num && (i != 0))
					{
						return i;												// returns row index
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

			int bottom = 0;
			int top = 10;
			int mid;

			binary_iterate = 0;


			while(bottom <= top)
			{
				
				mid = (bottom + top)/2;

				if(Matrix.value[a][mid] > first_num)
				{
					top = mid - 1;
				}
				else if(Matrix.value[a][mid] < first_num)
				{
					bottom = mid + 1;
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
			return iteration_time;				// returns linear search iteration
		}


		int binary_slice()
		{
			return binary_iterate;				// returns binary search iteration
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
																	// Storing all numbers into array 
			array.value[i][j] = entry;

		}

	}

	infile.close();



	row_index = array.linear_search(array);

	
	num_iterations = array.iteration_count();

	
	array.sort_row(&array, row_index);


	binary_index = array.binary_search(array,row_index);


	bin_iterate = array.binary_slice();

	


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


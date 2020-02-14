// Bryan Thiha 	
// 6002228585
// 02/12/20


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



class NumberSet
{
	
	public:
		Number num_array[10];


		bool check_independence(NumberSet obj)
		{
			
			bool output = true;

			for(int i = 0; i < 10; i++)											//Checking every index of both arrays
			{
				for(int j = 0; j < 10; j++)
				{
					if(num_array[i].get_value() == obj.num_array[j].get_value())
					{
						output = false;
					}
				}
			}

			return output;										// will return true IFF all pairs are independent, else false

		}

};



int main()
{
	
	NumberSet set_array[20];

	string message = "Y";
	int entry;
	int independent;


	ifstream infile;	
	infile.open("input.txt");


	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			
			infile >> entry;
																	// Storing all numbers into an array 
			set_array[i].num_array[j].set_value(entry);
		}

	}

	infile.close();



	for(int k = 0; k < 19; k++)
	{
		for(int m = k + 1; m < 20; m++)
		{	
			
			independent = set_array[k].check_independence(set_array[m]);

			if(independent == false)
			{
				message = "N";
			}
		}

	}


	ofstream outfile;	
	outfile.open("output.txt");

	outfile << message;
	
	outfile.close();
	
}
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

			for(int i = 0; i < 10; i++)
			{
				for(int j = 0; j < 10; j++)
				{
					if(num_array[i].get_value() == obj.num_array[j].get_value())
					{
						output = false;
					}
				}
			}

			return output;
		}



};

int main()
{
	//NumberSet a, b;
	string out = "Yes sir";
	int b;
	NumberSet set_array[20];
	int x;

	ifstream infile;	
	infile.open("input2.txt");

	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			infile >> x;

			set_array[i].num_array[j].set_value(x);

			cout << " " << set_array[i].num_array[j].get_value();
		}

		cout << endl;
	}

	infile.close();


	for(int k = 0; k < 19; k++)
	{
		for(int m = k + 1; m < 20; m++)
		{	
			b = set_array[k].check_independence(set_array[m]);
			cout << b << endl;

			if(b == false)
			{
				out = "No sir";
			}
		}

	}

	cout << out << endl;

	ofstream outfile;	
	outfile.open("output.txt");	
	outfile << out;
	
	outfile.close();


	
}
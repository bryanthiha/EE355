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
		}






};

int main()
{
	NumberSet a, b;

	NumberSet set_array[20];

	int a[10];
	int x, y, z;
	ifstream infile;	
	infile.open("input.txt");

	for(int i = 0; i < 20; i++)	
	{
		infile >> a[i];
		cout << a[i] << endl;
	}	
	infile.close();


	
}
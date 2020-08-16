#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> my_vec(20); // init. size of 5

	for(unsigned int i=0; i < 20; i++)
	{
		my_vec[i] = -1;
	}


	//my_vec.push_back(10); 
	//my_vec.push_back(8);
	//my_vec[0] = 30;
	unsigned int i;

	for(i=0; i < my_vec.size(); i++)
	{
		if((i % 2) != 0)
		{
			my_vec[i] = -1 + i;
		}
		cout << my_vec[i] << " ";
	}

	cout << endl;

	
	return 0;
}

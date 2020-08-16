// Bryan Thiha 	
// 6002228585
// 02/26/20


#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class Person
{

	public:
		string Name;
		int Result;
		string array[3];
		
		void Print_Name(Person a, int i)
		{
			cout << a.array[i] << endl;

		} 

		void Set_Name(Person b, string x, int i)
		{

			b.array[i] = x;

		}
		int Is_Infected(Person a)
		{
			if(a.result == 666 || a.result == 999)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}


};

int main(int argc, char *argv[])
{
	
	Person p1;
	Person p2;
	Person p3;
	int a, c;
	int b = 0;

	string x = argv[1];
	string y = argv[2];							
	string z = argv[3];

	cout << x << endl;

	p1.Set_Name(p1,x,0);
	p2.Set_Name(p2,y,1);
	p3.Set_Name(p3,z,2);

	p1.array[0] = x;
	p2.array[1] = y;
	p3.array[2] = z;

	


	for(int i = 1; i <= 3; i++)
	{
		cout << "result for person " << i << ": ";
		cin >> a;

		if(a == 999 || a == 666)
		{
			b = a;
			c = i-1;

		}
	}


	cout << p1.Print_Name(p1,c) << endl;

	

}
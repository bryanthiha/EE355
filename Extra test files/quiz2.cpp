// Bryan Thiha 	
// 6002228585
// 03/09/20


#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

struct Person
{
	string name;
	int age;
};

int func1(Person *person)
{
	
	return (*person).age;
}

int main
{
	Person p1;
	string n;
	int a;

	cin >> n;
	cout << endl;

	cin >> a;
	cout << endl;

	p1.name = n;
	p1.age = a;

	int x = func1(&p1);

	cout << x << endl;

	return 0;

}
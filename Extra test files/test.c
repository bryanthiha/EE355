#include <stdlib.h>
#include <stdio.h>


using namespace std;

int main()
{

	int a[] = {5, 3, 4, 5, 5, 7, 7, 7, 8, 3, 3, 4, 10, 12, 7};
	int b[sizeof(a)];
	int c[sizeof(a)];
	int n;
	int k = 3;
	int count = 1;

	for (int j = 0; j < sizeof(a); j++)
	{

		n = a[j];

		for (int i = j + 1; i < sizeof(a); i++)
		{

			if (a[i] == n)
			{
				count++;
			}
		}

		if(count > 1)
		{
			b[j] = count;
			c[j] = n;
		}
		count = 1;
	}

	for(int m = 0; m < sizeof(b); m++)
	{

		printf(" %d \n", c[k]);
		printf(" %l \n", sizeof(b));
	}

}
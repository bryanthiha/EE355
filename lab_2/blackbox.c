// Bryan Thiha 	6002228585

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

 
int main(int argc, char *argv[])
{
	
	float x, y, d, z, zd;

	srand(time(0));								// To generate a different random variable every time same inputs entered

	x = atof(argv[1]);
	y = atof(argv[2]);							// Converting input args to float
	d = atof(argv[3]);

	z = (x*x) + (y*y);

	int a = d*z;


	float e = rand()% a + 1;


	zd = z + e;


	if(argc < 2)
	{

    	printf("%s expects 3 numbers to be entered on the command line \n", argv[0]);

  	}

  	else
  	{

  		printf("%f\n", zd);
  
  	}
	
}



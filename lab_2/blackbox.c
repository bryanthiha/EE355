#include <stdlib.h>
#include <stdio.h>
using namespace std;

 

int main(int argc, char *argv[])
{
	float x, y, d, z, zd;
	x = atof(argv[1]);
	y = atof(argv[2]);
	d = atof(argv[3]);

	z = (x*x) + (y*y);

	int a = d*z;

	float e = rand()% a + 1;

	//printf("%f \n", e);

	zd = z + e;

	if(argc < 2)
	{

    	printf("%s expects 3 numbers to be entered on the command line \n", argv[0]);

  	}

  	else
  	{
  		//printf("%f\n%f\n%f\n%f \n\n", x, y, d, z);

  		printf("%f\n", zd);

  
  	}

  		
}



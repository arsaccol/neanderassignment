// The sum of the first n odd integers is n squared

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef unsigned char uint;

uint n_squared(uint n);
uint square_root(uint n, uint* out_fraction); 

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		printf("Usage: program.exe <number>\n");
		exit(-1);
	}
	uint n = atoi(argv[1]);


	//uint squared = n_squared(n);
	uint fraction = 0;
	uint sq_root = square_root(n, &fraction);
	
	//printf("%u squared is: %u\n", n, squared);
	printf("The square root of %hu is %hu.%hu\n", n, sq_root, fraction);
	printf("(With the decimal part being a single byte representation)\n");
    return 0;
}

//	Get the square of a given positive integer n.
//	Method: given n, sum up the first n odd naturals.
//	The obtained sum is the square of n. 
uint n_squared(uint n)
{
	uint sum = 0;
	uint odd = 1;
	
	for(uint i = 0; i < n; ++i)
	{
		sum += odd;
		odd += 2;
	}
	return sum; 
}


//	Given a square m, subtract decreasing odd numbers,
//	starting by the first one that is less than or equal to m.
//	When the next number to subtract is less than 0,
//	we have done the operation n times, where n is the
//	square root we wish to find.
uint square_root(uint m, uint* out_fraction)
{
	uint frac_m = m;

	if(m > 127)
	{
		*out_fraction = 0;
		return -1;
	}
	uint odd = 1;
	uint counter = 0;

	// calculate integer
	while( m >= odd )
	{
		m -= odd;
		odd += 2;
		counter += 1;
	}

	// calculate fraction
	uint fraction = 0;
	for(int i = 1; i <= 8; ++i)
	{
		fraction *= 2;
		m *= 2;
		if(m >= odd)
		{
			m -= odd;
			++fraction;
		}
	}

	*out_fraction = fraction;
	return counter;
}

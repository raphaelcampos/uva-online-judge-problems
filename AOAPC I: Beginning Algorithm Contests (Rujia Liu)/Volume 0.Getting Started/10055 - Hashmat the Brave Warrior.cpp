#include "stdio.h"
#include "iostream"

#include "cmath"

using namespace std;


int main(int argc, char const *argv[])
{
	long long int i,j;
	while ( scanf ("%lld %lld", &i, &j) != EOF ) {
		i -= j;
		 
		printf("%lld\n", (2*(i > 0) - 1)* i);
	}
	
	/* code */
	return 0;
}
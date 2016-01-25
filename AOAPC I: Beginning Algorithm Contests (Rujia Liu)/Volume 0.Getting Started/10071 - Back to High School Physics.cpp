#include "stdio.h"

int main(int argc, char const *argv[])
{
	int v,t;
	while ( scanf ("%d %d", &v, &t) != EOF ) {
		printf("%d\n",  (v*t) << 1);
	}
	
	/* code */
	return 0;
}
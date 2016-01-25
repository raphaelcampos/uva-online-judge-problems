#include "stdio.h"

int main(int argc, char const *argv[])
{
	int v, T;
	scanf ("%d", &T);
	while ( T-- ) {
		int N, yard, animals, f;
		scanf ("%d", &N);
		unsigned int sum = 0;
		while (N--){
			scanf("%d %d %d", &yard, &animals, &f);
			sum += yard*f;
		}
		printf("%d\n",  sum);
	}
	
	/* code */
	return 0;
}
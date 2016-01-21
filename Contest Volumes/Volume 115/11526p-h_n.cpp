#include "stdio.h"
#include "iostream"
#include <cstdlib>

#include "cmath"

using namespace std;


int main(int argc, char const *argv[])
{
	int T, n, i, prev, curr;
	long long int sum;

	scanf("%d", &T);
	while(T--)
	{	
		scanf("%d", &n);
		
		i = 0;
		sum = 0;
		curr = n;
		while(curr > i){
			prev = curr;
			curr = n/(i+1);

			if(curr == i){
				sum +=  i*(prev - curr);
				break;
			}
			sum += curr + i*(prev - curr);
			++i;
		}

		printf("%lld\n",sum);
	}
	/* code */
	return 0;
}
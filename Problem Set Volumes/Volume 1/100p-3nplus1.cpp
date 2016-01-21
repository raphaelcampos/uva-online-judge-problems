#include "stdio.h"
#include "iostream"

#include "cmath"

using namespace std;

#define MAX 4000001

unsigned int M[MAX] = {0};

unsigned int cycle_length(unsigned int n){
	unsigned int count = 0;
	while(n != 1){
		if(n < MAX && M[n] != 0){
			return count + M[n];
		}

		if (n % 2) {
			n = (3*n + 1) >> 1;
			count += 2;
		}else{
			n >>= 1;
			count++;	
		}
		
	}

	return count + 1;
}

int main(int argc, char const *argv[])
{
	unsigned int i,j;
	
	while ( scanf ("%d %d", &i, &j) != EOF ) {
		unsigned int k = i, l = j;
		if(l < k)
			std::swap(k, l);

		unsigned int m = 0;
		for (; k <= l; ++k)
		{
			unsigned int n = k;
			unsigned int count = 0;
			while(n != 1){
				if(n < MAX && M[n] != 0){
					count += M[n];
					break;
				}

				if (n % 2) {
					n = (3*n + 1) >> 1;
					count += 2;
				}else{
					n >>= 1;
					count++;	
				}
				
			}

			M[k] = count;
			if(m < M[k]){
				m = M[k];
			}
		}

		cout << i << " " << j << " " << m + 1 << endl;
	}
	
	/* code */
	return 0;
}
#include "stdio.h"
#include "iostream"
#include <cstdlib>

#include "cmath"

using namespace std;

int main(int argc, char const *argv[])
{
	int T, Q;
	int d, s;
	char r;
	unsigned int c_l[10], c_nl[10];
	unsigned sum = 0;

	scanf("%d", &T);
	while(T--){
		for (int i = 0; i < 10; ++i)
		{
			c_l[i] = 0;
			c_nl[i] = 0;
		}
		
		scanf("%d", &Q);
		while(Q--){
			scanf("%d %d %c", &d, &s, &r);
			c_l[d-1] += (s && r == 'c');
			c_nl[d-1] += (!s && r == 'i');
		}

		sum = 0;
		for (int i = 0; i < 10; ++i)
		{
			for (int j = i + 1; j < 10; ++j)
			{
				sum += c_nl[i]*c_l[j];
			}
		}

		printf("%d\n", sum);
	}
	
	return 0;
}
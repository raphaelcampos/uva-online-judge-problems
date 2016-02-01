#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int depth, iteration, T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &depth, &iteration);

		unsigned int v = iteration - 1;
		int i = depth - 1;
		int result = 1 << (i); // 2^(depth - 1)

		for (; i && v; --i)
		{
			result += (v & 1) << (i-1);
			v >>= 1;			
		}

		printf("%d\n", result);
	}
}
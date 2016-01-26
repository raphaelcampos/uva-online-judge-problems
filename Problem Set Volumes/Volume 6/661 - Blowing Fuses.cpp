#include "stdio.h"
#include <iostream>

#include <vector>
#include <map>

using namespace std;

#define MAX 50

int main(int argc, char const *argv[])
{
	int cap[MAX] = {0};
	int toggle[MAX] = {false};

	int n,m,c, s = 0;
	while(scanf("%d %d %d", &n, &m, &c) != EOF && n != 0 && m != 0 && c != 0){

		if (s > 0)
		{
			
		}

		for (int i = 0; i < n; ++i)
		{
			scanf("%d", cap + i);
			toggle[i] = false;
		}

		int capacity = 0;
		int max_cap = 0;
		bool blown = false;
		for (int i = 0; i < m; ++i)
		{
			int d;
			scanf("%d", &d);
			blown = blown || (capacity > c);

			toggle[d-1] = !toggle[d-1];

			if(toggle[d-1]){
				capacity += cap[d-1];
			}else{
				capacity -= cap[d-1];
			}

			max_cap = std::max(max_cap, capacity);
		}
		blown = blown || (capacity > c);

		printf("Sequence %d\n", ++s);
		if(blown){
			printf("Fuse was blown.\n");
		}else{
			printf("Fuse was not blown.\n");
			printf("Maximal power consumption was %d amperes.\n", max_cap);
		}
		printf("\n");
	}

	return 0;
}
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{

	string line;
	int iline = 0;
	int m = -1;
	int q = 0;

	int count = 0;

	while(scanf("%d %d", &m, &q) && (m || q)){
		count += 1;
		
		int marbles[m];
		int query;

		printf("CASE# %d:\n", count);

		//marbles
		for (int i = 0; i < m; i++)
			scanf("%d", &marbles[i]);

		//sort
		sort(marbles, marbles + m);

		//queries
		for (int i = 0; i < q; i++) {
			scanf("%d", &query);
			int *point = lower_bound(marbles, marbles+m, query);
			int pos =  point - marbles;
			if(*point == query) {
				printf("%d found at %d\n", query, pos+1);					
			}
			else {
				printf("%d not found\n", query);
			}
		}
	}

	/* code */
	return 0;
}
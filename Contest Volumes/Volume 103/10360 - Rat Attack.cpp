#include "stdio.h"
#include <iostream>

#include <vector>
#include <map>

#include <algorithm>

#include <iomanip>
#include <string.h>

#include <sstream>

using namespace std;

#define MAX_CELLS 1025

int main(int argc, char const *argv[])
{
	unsigned int killed[MAX_CELLS][MAX_CELLS];
	int S;
	scanf("%d", &S);

	while(S--){
		int power, rats;
		scanf("%d\n%d", &power,&rats);
		//scanf("%d", );

		memset(killed, 0, MAX_CELLS*MAX_CELLS*sizeof(unsigned int));

		int maxx = 0, maxy = 0;
		while(rats--){
			int x, y, pop;
			scanf("%d %d %d", &x, &y, &pop);
			for (int i = std::max(x - power, 0); i <= std::min(x + power, MAX_CELLS - 1); ++i)
			{
				for (int j = std::max(y - power, 0); j <= std::min(y + power, MAX_CELLS - 1); ++j)
				{
					killed[i][j] += pop;
					if(killed[maxx][maxy] < killed[i][j]){
						maxx = i;
						maxy = j;
					}
				}
			}
		}

		printf("%d %d %d\n", maxx, maxy, killed[maxx][maxy]);

	}

	return 0;
}

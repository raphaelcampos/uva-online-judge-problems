#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 5

bool tour[MAX][MAX] = {{0, 1, 1, 0, 1}, {1, 0, 1, 0, 1}, {1, 1, 0, 1, 1}, {0, 0, 1, 0, 1}, {1, 1, 1, 1, 0}};
bool maked[MAX][MAX] = {0};

void houses(int n, int i, char seq[10]){
	seq[n] = '1' + i;

	if(n == 8){
		printf("%s\n", seq);
		return;
	}

	for (int j = 0; j < MAX; ++j)
	{
		if(tour[i][j] && !maked[i][j]){
			maked[i][j] = maked[j][i] = true;
			houses(n + 1, j, seq);
			maked[i][j] = maked[j][i] = false;
		}
	}
}

int main(int argc, char const *argv[])
{
	char seq[10] = {'\0'};

	houses(0, 0, seq);
	
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

#include <iostream>


#include "string.h"

using namespace std;

#define INF 9999999

#define MAX 101
int n;
int M[MAX][MAX] = {0};

int mem[MAX][MAX][MAX][MAX] = {0};

int g_soma_maxima(int i, int j, int maxi,  int maxj){
	int max_ate_aqui = 0;
	int max_terminando_aqui = 0;

	int n = (maxj == j)? maxi : maxj;
	//printf("n: %d, %d\n", i, n);
	int ini = 0;
	int fim = n;
	for (int k = i + 1; k <= n + 1; ++k)
	{
		
		if(maxj == j)
			max_terminando_aqui = (max_terminando_aqui + M[k-1][j] >= 0) ? max_terminando_aqui + M[k-1][j] : 0;
		else
			max_terminando_aqui = (max_terminando_aqui + M[i][k-1] >= 0) ? max_terminando_aqui + M[i][k-1] : 0;

		max_ate_aqui = (max_ate_aqui >= max_terminando_aqui) ? max_ate_aqui : max_terminando_aqui;
		
	}

	return max_ate_aqui;
}

int max_sum(int i, int j, int maxi, int maxj){
	if(mem[i][j][maxi][maxj] != -1)
		return mem[i][j][maxi][maxj];

	if(i < 0 || j < 0 || maxi < 0 || maxj < 0 
		|| i >= n || j >= n || maxi  >= n || maxj >= n)
		return 0;

	if(maxi < i || maxj < j)
		return 0;

	if(maxi - i == 0 && maxj - j == 0){
		return mem[i][j][maxi][maxj] = M[i][j];
	}

	//printf("%d,%d, %d, %d\n", i, j ,maxi, maxj);

	int go = max_sum(i, j, maxi, maxj - 1);
	int r = max(g_soma_maxima(i, maxj, maxi, maxj) + go, go);
	go = max_sum(i, j + 1, maxi, maxj);
		r = max(r, max(g_soma_maxima(i, j, maxi, j) + go, go));
	go = max_sum(i + 1, j, maxi, maxj);
		r = max(r, max(g_soma_maxima(i, j, i, maxj) + go, go));
	go = max_sum(i, j, maxi - 1, maxj);
	return  mem[i][j][maxi][maxj] = max(r, max(g_soma_maxima(maxi, j, maxi, maxj) + go, go));

}

int max_sum6(){
	int maxSubRect = -127*100*100; // lowest possible value for this problem
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) // start coord
	for (int k = i; k < n; k++) for (int l = j; l < n; l++) { // end coord
		int subRect = 0; // sum items in this sub-rectangle
		for (int a = i; a <= k; a++) for (int b = j; b <= l; b++)
			subRect += M[a][b];
		maxSubRect = max(maxSubRect, subRect); // keep largest so far
	}

	return maxSubRect;
}

int main(int argc, char const *argv[])
{

	while(scanf("%d", &n) != EOF){
		
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				scanf("%d", &M[i][j]);
				if (i > 0) M[i][j] += M[i - 1][j];
				if (j > 0) M[i][j] += M[i][j - 1];
				if (i > 0 && j > 0) M[i][j] -= M[i - 1][j - 1];
			}
		}

		int maxSubRect = -127*100*100; // lowest possible value for this problem
		
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) // start coord
		for (int k = i; k < n; k++) for (int l = j; l < n; l++) { // end coord
			int subRect = M[k][l]; // this is sum of all items from (0, 0) to (k, l): O(1)
			if (i > 0) subRect -= M[i - 1][l]; // O(1)
			if (j > 0) subRect -= M[k][j - 1]; // O(1)
			if (i > 0 && j > 0) subRect += M[i - 1][j - 1]; // inclusion-exclusion: O(1)
			maxSubRect = max(maxSubRect, subRect);
		}

		//printf("n:%d\n", n);*/
		//printf("%d\n", max_sum(0, 0, n - 1, n - 1));
		printf("%d\n", maxSubRect);
	}

	return 0;
}
#include "stdio.h"
#include "iostream"
#include <cstdlib>

#include "cmath"

using namespace std;

#define MAX_Q 50000

unsigned int merge_and_count(int *d, int *s, char *r, unsigned int *c, int b, int e, int m){
	
	int n = e - b + 1;

	int size = sizeof(int)*n;
	int *buffer_d = (int*)malloc(size), *buffer_s = (int*)malloc(size);
	unsigned int *buffer_c = (unsigned int*)malloc(sizeof(unsigned int)*n);
	size = sizeof(char)*n;
	char *buffer_r = (char*)malloc(size);


	int i = b, j = m + 1, k = 0, id;
	unsigned int count = 0;
	while(i < m + 1 && j <= e){
		if(d[i] < d[j]){
			id = i;
			//c[i] += (s[j] && (r[i] == 'i' && r[j] == 'c'));
			//count += (s[j] && (r[i] == 'i' && r[j] == 'c')) + c[j];
			++i;
		}else{
			//count += (s[i] && (r[j] == 'i' && r[i] == 'c') && d[i] != d[j]);
			id = j;
			++j;
		}
		buffer_d[k] = d[id];
		buffer_s[k] = s[id];
		buffer_r[k] = r[id];
		buffer_c[k] = c[id];
		++k;
	}

	if (j <= e)
	{
		for (int i = j; i <= e; ++i)
		{
			buffer_d[k] = d[i];
			buffer_s[k] = s[i];
			buffer_r[k] = r[i];
			buffer_c[k] = c[i];
			k++;
		}
	}else{
		for (int i = i; i <= m; ++i)
		{
			buffer_d[k] = d[i];
			buffer_s[k] = s[i];
			buffer_r[k] = r[i];
			buffer_c[k] = c[i];
			k++;
		}
	}

	k = 0;
	for (int i = b; i <= e; ++i)
	{
		d[i] = buffer_d[k];
		s[i] = buffer_s[k];
	 	r[i] = buffer_r[k];
	 	c[i] = buffer_c[k];
	 	++k;
	}

	free(buffer_d);
	free(buffer_s);
	free(buffer_r);
	free(buffer_c);

	return count;
}

unsigned merge_and_sort(int *d, int *s, char *r, unsigned int *c, int b, int e){
	if (b >= e)
		return 0;

	//for (int i = b; i <= e; ++i)
	//{
	//	printf("%d ", d[i]);
	//}
	//printf("\n");

	int m = (b + e)/2;
	
	return merge_and_sort(d, s, r, c, b, m)
		+ merge_and_sort(d, s, r, c, m + 1, e)
		+ merge_and_count(d, s, r, c, b, e, m);
}

int main(int argc, char const *argv[])
{
	int T, Q;
	int d[MAX_Q], s[MAX_Q];
	unsigned int c[MAX_Q];
	char r[MAX_Q];

	/*printf("%d\n", 1);
	for (int i = 0; i < 1; ++i)
	{
		int Q = rand()%MAX_Q;
		printf("%d\n", Q);
		for (int j = 0; j < Q; ++j)
		{
			char rt[2] = {'i', 'c'};
			printf("%d %d %c\n", 1 + rand()%10 , rand()%2, rt[rand()%2]);
		}
	}

	return 0;*/

	scanf("%d", &T);
	while(T--){
		int n;
		
		scanf("%d", &Q);
		printf("%d %d\n", T, Q);
		n = Q;
		while(Q--){
			c[Q] = 0;
			scanf("%d %d %s", &d[n-Q-1], &s[n-Q-1], &r[n-Q-1]);
		}
		
		printf("%d\n", merge_and_sort(d, s, r, c, 0, n-1));
		for (int i = 0; i < n; ++i)
		{
			printf("%d ", d[i]);
		}
		printf("\n");
	}
	
	return 0;
}
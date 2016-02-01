#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define MAX 51

struct dna
{
	char seq[MAX];
	int inversion;
};

bool compare (dna i, dna j) { return (i. inversion < j.inversion); }

int merge_and_count(char *A, char *buffer, int ini, int fim, int meio){

	memset(buffer, 0, sizeof(char)*(fim-ini+1));

	int count = 0;

	int i = ini;
	int j = meio + 1;
	
	int k = 0;
	while(i < meio + 1 && j <= fim){
		if(A[i] <= A[j]){
			buffer[k] = A[i];
			i++;
		}else if(A[i] > A[j]){
			buffer[k] = A[j];
			count += meio - i + 1;
			j++;
		}
		k++;
	}

	if(i < meio + 1){
		memcpy(buffer + k, A + i, sizeof(char)*(meio-i+1));
	}else{
		memcpy(buffer + k, A + j, sizeof(char)*(fim-j+1));
	}
	
	memcpy(A + ini, buffer, sizeof(char)*(fim-ini+1));

	return count;
}

int sort_and_count(char A[], char buffer[], int ini, int fim){

	if(fim + 1 - ini <= 1){
		return 0;
	}else{
		int meio = (ini + fim)/2;
		return sort_and_count(A, buffer, ini, meio) +
		 sort_and_count(A, buffer, meio + 1, fim) + 
		 merge_and_count(A, buffer, ini, fim, meio);
		 ;
	}
}

int main(int argc, char const *argv[])
{
	int n, m, t, i;
	char buffer[MAX], seq[MAX];;

	scanf("%d", &t);
	while(t--){
		
		scanf("%d %d", &n, &m);
		
		dna *dnas =  new dna[m];
		i = 0;
		while(m--){
			scanf("%s", dnas[i].seq);
			strcpy(seq, dnas[i].seq);
			dnas[i].inversion = sort_and_count(seq, buffer, 0, n - 1);
			++i;
		}

		std::stable_sort(dnas, dnas + i, compare);

		for (int j = 0; j < i; ++j)
		{
			printf("%s\n", dnas[j].seq);
		}

		delete [] dnas;

		if(t >= 1)
			printf("\n");
	}

	return 0;
}
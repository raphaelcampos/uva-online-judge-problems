#include "stdio.h"
#include <iostream>

#include <vector>
#include <map>

#include <algorithm>

#include <iomanip>
#include <string.h>

using namespace std;

unsigned long long int factorial(int n){
	unsigned long long int fact = 1;
	for (int i = 2; i <= n; ++i)
	{
		fact *= i;
	}
	return fact;
}

int main(int argc, char const *argv[])
{
	unsigned long long int i;
	int T;
	scanf("%d", &T);
	while(T--){
		char word[50];
		scanf("%s", word);
		scanf("%lld", &i);
		
		int n = strlen(word);
		unsigned long long int rep = factorial(n - 1);
		

		std::sort(word, word + n);
		std::vector<char> elems(word, word + n);
		for (int j = n - 1; j > 0; --j)
		{
			unsigned int pos = i/rep;
			if (pos >= elems.size())
			{
				printf("pos : %d\n", pos);
				pos = elems.size() - 1;
			}
			printf("%c", elems[pos]);
			elems.erase(elems.begin() + pos);

			i %= rep;
			rep /= j;
		}
		printf("%c\n", elems[0]);
	}

	

	return 0;
}

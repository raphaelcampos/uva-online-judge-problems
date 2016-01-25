#include "stdio.h"
#include <iostream>
#include <string.h>

#define MAX 100

char lines[MAX][MAX];

int main(int argc, char const *argv[])
{

	std::string line;
	int n = 0;
	int columns = 0;
	while ( std::getline(std::cin, line) ) {
		strcpy(lines[n], line.c_str());
		n++;
		int size = line.size();
		columns = std::max(columns, size);
	}

	for (int i = 0; i < columns; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(lines[n - j - 1][i] != '\0')
				printf("%c", lines[n - j - 1][i]);
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
	
	/* code */
	return 0;
}
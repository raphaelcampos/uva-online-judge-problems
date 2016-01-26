#include "stdio.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>     /* atoi */

#define  is_digit(ch) (ch >= '0' && ch <= '9')

int main(int argc, char const *argv[])
{

	std::string line;
	int n = 0;
	int columns = 0;
	bool first = true;
	int size, occur = 0;
	while ( std::getline(std::cin, line) ) {
		for (int i = 0; i < line.size(); ++i)
		{
			char ch = line[i];

			if (ch == '\"' && occur == 0)
			{
				printf("``");
				++occur;
			}else if (ch == '\"' && occur == 1)
			{
				printf("\'\'");
				occur = 0;
			}else{
				printf("%c",ch);
			}


		}

	
		printf("\n");
		
	}

	/* code */
	return 0;
}
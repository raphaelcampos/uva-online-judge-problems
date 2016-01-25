#include "stdio.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>     /* atoi */

#define  is_digit(ch) (ch >= '0' && ch <= '9')

int main(int argc, char const *argv[])
{

	std::string line;
	while ( std::getline(std::cin, line) ) {
		
		if(line == "0") return 0;

		int result = 0;
		for (int i = 0; i < line.size(); ++i)
		{
			int k = line.size() - i;
			
			int digit = (line[i] - '0');
			
			result += digit*((1 << k) - 1);

			if(digit == 2)
				break;
		}

		printf("%d\n", result);
		
	}

	/* code */
	return 0;
}
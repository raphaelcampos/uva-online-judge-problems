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
	int size, rep;
	while ( std::getline(std::cin, line) ) {
		
		if((size=line.length()==0)){printf("\n");continue;}

		rep = 0;
		for (int i = 0; i < line.size(); ++i)
		{
			char ch = line[i];

			if(is_digit(ch)){
				rep += ch - '0';
			}else if (ch == '!' || ch == '\n'){
				printf("\n");
				rep = 0;
			}else{
				for (int j = 0; j < rep; ++j)
				{
					if (ch == 'b')
					{
						printf("%c", ' ');
					}else{
						printf("%c", ch);
					}
					
				}
				rep = 0;
			}
		}

	
		printf("\n");
		
	}

	/* code */
	return 0;
}
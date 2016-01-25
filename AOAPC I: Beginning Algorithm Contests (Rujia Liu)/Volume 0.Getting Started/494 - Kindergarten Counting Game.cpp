#include "stdio.h"
#include <iostream>

#define is_letter(ch) ( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') )

int main(int argc, char const *argv[])
{
	std::string line;
	while ( std::getline(std::cin, line) ) {
		
		int i = 0;
		int words = 0;
		while(line[i] != '\0'){
			
			words += is_letter(line[i]) && !is_letter(line[i+1]);
			++i;
		}

		printf("%d\n", words);
	}
	
	/* code */
	return 0;
}
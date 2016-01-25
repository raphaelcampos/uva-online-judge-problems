#include "stdio.h"
#include <iostream>

int main(int argc, char const *argv[])
{

	std::string line;
	while ( std::getline(std::cin, line) ) {
		int i = 0;
		std::string out;
		while(line[i] != '\0'){
			out += line[i] - 7;
			++i;
		}

		std::cout << out << std::endl;
	}
	
	/* code */
	return 0;
}
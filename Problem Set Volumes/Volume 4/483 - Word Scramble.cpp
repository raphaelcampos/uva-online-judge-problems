#include "stdio.h"
#include <iostream>

#include <vector>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	
	std::string line;
	
	while( std::getline(std::cin, line) ){
		std::string buffer = line;

		int j = line.size() - 1;
		for (int i = 0; i < line.size(); ++i)
		{
			bool is_end = i == line.size() - 1;

			if(is_end){
				buffer[j] = line[i];
			}

			if(line[i] == ' ' || is_end){
				int end = i - (line.size() - j);
				j = line.size() - 1;
				for (int k = i - !(is_end); k > end; --k, --j)
				{
					line[k] = buffer[j];
				}

				j = line.size() - 1;
			}else{
				buffer[j] = line[i];
				--j;
			}
		}

		cout << line << endl;

	}

	return 0;
}
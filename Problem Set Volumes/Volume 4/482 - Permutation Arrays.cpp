#include "stdio.h"
#include <iostream>

#include <vector>
#include <map>

#include <algorithm>

#include <iomanip>
#include <string.h>

#include <sstream>

using namespace std;

int main(int argc, char const *argv[])
{
	unsigned long long int i;
	int T;
	scanf("%d", &T);
	int j = 0;
	while(T--){
		std::vector<float> v;
		int n;
		int m = 0, i = 0;

		if(j){
			printf("\n");
		}

		string line;
		
		while(getline(cin, line) && i < 2 ){
			++i;
		}

		stringstream str(line);		

		while(str >> n){
			v.push_back(n);
		}

		std::map<int, char*> map;
		for (int i = 0; i < v.size(); ++i)
		{
			char *d = new char[255];
			scanf("%s", d);
			map[v[i]] = d;
		}

		for (std::map<int, char*>::iterator it = map.begin(); it != map.end(); ++it)
		{
			printf("%s\n", it->second);
		}
		j++;

	}

	

	return 0;
}

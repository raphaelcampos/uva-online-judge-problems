#include "stdio.h"
#include <iostream>

#include <vector>
#include <map>

using namespace std;

std::vector<int> mapmaker(int B, int D, int C, std::vector<int> &bounds){
	int c0 = B;
	int d = D;
	std::vector<int> Cs;
	Cs.push_back(C);

	for (int i = bounds.size() - 1; i > 1 ; i -= 2)
	{
		c0 -= C*bounds[i-1];
		C = C*(bounds[i] - bounds[i-1] + 1);
		Cs.push_back(C);
	}

	c0 -= Cs.back()*bounds[0];
	Cs.push_back(c0);
	return Cs;
}

int main(int argc, char const *argv[])
{
	int n, r;
	std::string line;
	std::vector< std::vector<int> > Cs;
	std::map<std::string, int> names;
	std::vector<int> dims;

	scanf("%d %d", &n, &r);
	int i = 0;
	while ( n-- ) {
		std::string name;
		int C, D, B;
		cin >> name;
		scanf("%d %d %d", &B, &C, &D);
		
		int dim = D;
		std::vector<int> bound;
		while(dim--)
		{
			int U, L;
			scanf("%d %d", &L, &U);
			bound.push_back(L);
			bound.push_back(U);
		}

		names[name] = i;
		
		i++;
		
		Cs.push_back(mapmaker(B,D,C,bound));
	}

	while( r-- ){
		std::string name;
		cin >> name; 
		int id = 0;
		int dd = names[name];
		std::vector<int> &cs = Cs[dd];
		printf("%s[", name.c_str());
		for (int i = cs.size() - 2; i >= 0; --i)
		{
			int j;
			scanf("%d", &j);
			id += cs[i]*j;

			if(i)
				printf("%d, ", j);
			else
				printf("%d", j);
		}
		id += cs.back();

		printf("] = %d\n", id);
	}


	/* code */
	return 0;
}
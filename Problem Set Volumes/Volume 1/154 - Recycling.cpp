#include <iostream>
#include <stdio.h>

#define MAX_CITIES 100
#define MAX_BINS 5

using namespace std;

int matches[MAX_CITIES];

string bins[MAX_CITIES][MAX_BINS];


int main(int argc, char const *argv[])
{

	string line;
	int iline = 0;
	while(getline(cin, line) && line != "#"){
		if(line[0] == 'e'){
			int maxi = 0;

			for (int i = 0; i < iline; ++i)
			{
				for (int j = 0; j < iline; ++j)
				{
					if(i != j){
						for (int k = 0; k < MAX_BINS; ++k)
						{
							for (int l = 0; l < MAX_BINS; ++l)
							{
								matches[i] += bins[i][k] == bins[j][l];
							}
						}
						if(matches[maxi] < matches[i]){
							maxi = i;
						}
					}
				}

			}

			printf("%d\n", maxi + 1);

			iline = 0;
			continue;
		}

		for (int i = 0; i < line.size(); i += 4)
		{
			string bin;
			for (int j = i; j < i + 3; ++j)
			{
				bin += line[j];
			}

			bins[iline][i/4] = bin;
		}

		/*for (int i = 0; i < MAX_BINS; ++i)
		{
			printf("%s", bins[iline][i].c_str());
		}
		printf("\n");*/

		matches[iline] = 0;

		++iline;

	}


	/* code */
	return 0;
}
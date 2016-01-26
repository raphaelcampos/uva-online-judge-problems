#include "stdio.h"
#include <iostream>

#include <vector>
#include <map>

#include <iomanip>

using namespace std;

#define MAX 50

char get_code(char ch){
	
	switch(ch){
		case 'B':
		case 'P':
		case 'F':
		case 'V':
			return '1';
		case 'C':
		case 'K':
		case 'S':
		case 'G':
		case 'J':
		case 'Q':
		case 'X':
		case 'Z':
			return '2';
		case 'D':
		case 'T':
			return '3';
		case 'L':
			return '4';
		case 'M':
		case 'N':
			return '5';
		case 'R':
			return '6';
		default:
			return '0';
	}
}

int main(int argc, char const *argv[])
{
	string line;
	
	cout << setw(9) << "" << "NAME" << setw(21) << "" << "SOUNDEX CODE" << endl;
	while(getline(cin, line)){

		string soundex;
		soundex += line[0];
		for (int i = 1; i < line.size() && soundex.size() < 4; ++i)
		{
			char code = get_code(line[i]);
			if(get_code(line[i-1]) == code || code == '0')
				continue;

			soundex += code;
		}

		for (int i = soundex.size(); i < 4; ++i)
		{
			soundex += '0';
		}

		cout << setw(9) << "" << line << setw(25 - line.size()) << "" << soundex << endl;
	
	}

	cout << setw(19) << "" << "END OF OUTPUT" << endl;

	return 0;
}

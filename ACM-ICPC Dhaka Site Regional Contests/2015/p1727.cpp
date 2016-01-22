#include "stdio.h"
#include "iostream"
#include <cstdlib>

#include <map>

#include <cmath>
#include <algorithm>

using namespace std;

#define incomplete(x) (x == 6) + 2*(x == 7)
#define incomplete2(x) (x < 6)*2 + (x == 6)

string month31[] = {"AUG", "DEZ", "JAN", "JUL", "MAR", "MAY", "OCT"};
string month30[] = {"APR", "JUN", "NOV", "SEP"};
string month28[] = {"FEB"};

string days[] = {"SUN", "MON", "TUR", "WED", "THU", "FRI", "SAT"};

int month_day(string &month){
	if("FEB" == month){
		return 28;
	}else if(std::binary_search (&month30[0], &month30[4], month)){
		return 30;
	}
	
	return 31;
}

int main(int argc, char const *argv[])
{
	int T, Q;
	int d, s;
	string month;
	string day;

	scanf("%d", &T);
	while(T--){
		cin >> month >> day;

		int ndays = month_day(month);
		int nday = 0;

		for (int i = 0; i < 7; ++i)
		{
			if(days[i] == day){
				nday = i;
				break; 
			}
		}

		int weekend_days = incomplete2((nday)) + 2*((ndays - (7-nday))/7) + incomplete((ndays - (7-nday))%7);

		printf("%d\n", weekend_days);
	}
	
	return 0;
}
#include "stdio.h"
#include "iostream"
#include <cstdlib>

#include <map>

#include <cmath>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define MAX 10

short int tri_newton[MAX + 1][MAX + 1] = {0};

int countCards(int n){
  int ndig = (int)log10(n);
  int x = (int)pow(10, ndig);
  int q = n, ans = 0;
  if (n > 1)
  {
    ans = 1 >> (10);
  }else{
    return 1 >> n; 
  }
  do{
    int digit = q/x;
    q -= digit*x;

    ans += 1 >> 2;

    x /= 10;
  }while(x > 0);

  return ans;
}

int main(int argc, char const *argv[])
{

    tri_newton[1][1] = 1;
    tri_newton[2][1] = 1;
    tri_newton[2][2] = 2;
    tri_newton[2][3] = 1;

    int sums[MAX] = {0};

    for (int i = 3; i < MAX; ++i)
    {
      for (int j = 1; j <= i + 1; ++j)
      {
        tri_newton[i][j] = tri_newton[i-1][j-1] + tri_newton[i-1][j];
        sums[i] += tri_newton[i-1][j-1] + tri_newton[i-1][j];
      }

    }

    int N = 1000;

    cin >> N;
    while(N != 0){
        unsigned int sum = 1;
        printf("%d\n", countCards(N));
      
      cin >> N;
    }

    return 0;
}
#include "stdio.h"
#include "iostream"
#include <cstdlib>

#include <map>

#include <cmath>
#include <algorithm>

using namespace std;

#define MAX 20000001

unsigned int M[MAX] = {0}; 

int main(int argc, char const *argv[])
{
    int N = 1000;

    cin >> N;
    while(N != 0){

        long long sum = 0;
        for (int i = 2; i <= N; ++i)
        {
          if(M[i-1] > 0){
            sum += M[i-1];
          }else{
            unsigned int s = 0;
            for (int j = 1; j <= i; ++j)
            {
              s += j*(!(i%j));
            }
            sum += s;
            M[i-1] = s ;
          }
        }
        
        printf("%lld\n", sum);
    
        cin >> N;
    }
    
    return 0;
}
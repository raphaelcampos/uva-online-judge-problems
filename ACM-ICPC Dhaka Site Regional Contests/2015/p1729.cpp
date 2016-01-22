#include "stdio.h"
#include "iostream"
#include <cstdlib>

#include <map>

#include <cmath>
#include <algorithm>

using namespace std;

#define MAX 100000

int LCSLength(char *X, char *Y, int n, int C[MAX][MAX]){

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            C[i][j] = 0;
        }
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            if (X[i] == Y[j])
                C[i][j] = C[i-1][j-1] + 1;
            else
                C[i][j] = std::max(C[i][j-1], C[i-1][j]);
        }
    }

}

int lcs( char *X, char *Y, int m, int n )
{
   int L[m+1][n+1];
   int i, j;
  
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
    
   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   return L[m][n];
}


int main(int argc, char const *argv[])
{
    int T, N, M;
    char S[MAX];
    int alpha_size = 'z' - 'a' + 1;
    int count[alpha_size];
    
    int c = 0;
    scanf("%d\n", &T);
    while(T--){
        scanf("%s", &S);

        for (int i = 0; i < alpha_size; ++i)
        {
            count[i] = 0;
        }

        int i = 0;
        while(S[i] != '\0'){            
            count[S[i] - 'a']++;
            ++i;  
        }

        printf("Case %d: %d\n", ++c, *std::min_element(count, count+alpha_size));
    }
    
    return 0;
}
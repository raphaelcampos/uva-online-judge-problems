#include "stdio.h"
#include "iostream"
#include <cstdlib>

#include <map>

#include <cmath>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define MAX 20000001

unsigned int M[MAX] = {0}; 
//std::set<int> MSET[MAX]; 

std::vector<int> primes;

#define is_prime(n) (M[n-1] - 1 == n)

unsigned int SMLCM4(int i){
  unsigned int s = i + 1;
  bool prime = true;
  float fsq_root = sqrt(i);
  int isq_root = (int) fsq_root;

  std::set<int> cset;

  if (primes.empty())
  {
    primes.push_back(i); 
    return s;
  }

  int j;
  std::vector<int>::iterator it = primes.begin();
  while(it != primes.end() && *it < fsq_root){
    s += (*it + i/(*it))*!(i%*it);
    ++it;
  }
  s += isq_root*(fsq_root == isq_root);

  if (*it > fsq_root && s == i + 1)
  {
    primes.push_back(i);
  }

  return s;
}

/*unsigned int SMLCM3(int i){
  unsigned int s = 0;
  bool prime = true;
  float fsq_root = sqrt(i);
  int isq_root = (int) fsq_root;

  std::set<int> cset;
  cset.insert(1);
  cset.insert(i);

  if (primes.empty())
  {
    primes.push_back(i); 
    //cout << "set : ";
    for(std::set<int>::iterator it = cset.begin(); it != cset.end(); ++it){
      s += *it;
      //cout << *it << " ";
    }
    //cout << endl;
    return s;
  }

  int j;
  int v;
  std::vector<int>::iterator it = primes.begin();
  while(it != primes.end() && *it <= fsq_root){
    //s += (*it + i/(*it))*!(i%*it);
    v = *it;
    while(v <= fsq_root && !(i%v)){
      cset.insert(v);
      cset.insert(MSET[i/(v) - 1].begin(), MSET[i/(v) - 1].end());
      v *= *it;
    }
    ++it;
  }
  
  for(std::set<int>::iterator it = cset.begin(); it != cset.end(); ++it){
    s += *it;
  }
  
  if (*it > fsq_root && s == i + 1)
  {
    primes.push_back(i);
  }

  MSET[i-1] = cset;

  return s;
}*/

unsigned int SMLCM2(int i){
  unsigned int s = 1 + i;
  bool prime = true;
  float fsq_root = sqrt(i);
  int isq_root = (int) fsq_root;
  for (int j = 2; j < fsq_root; ++j)
  {
    s += (j + i/j)*!(i%j);
  }
  s += isq_root*(fsq_root == isq_root);

  return s;
}

unsigned int SMLCM(int i){
  unsigned int s = i;
  int v = i, j = 0;

  float fsq_root = sqrt(i);
  int isq_root = (int) fsq_root;

  if(fsq_root == isq_root){
    if(s == i + 1){
      primes.push_back(i);
    }
    return M[i-1] = isq_root*M[isq_root-1] + M[isq_root-1] - isq_root;
  }

  if(!primes.empty()){
    int div_count = 0, p, count = 0;
    
    for (p = 0; p < primes.size() && (primes[p] <= fsq_root || div_count); ++p)
    {
      int v = i;
      while(v%primes[p] == 0){
        v /= primes[p];
        s += v;
        ++div_count;
      }

      count += v < i;
      if(v < i){
        s += M[v-1] - v - 1;
      }
    }
    s += count > 0;
    //printf("c:%d\n", count);
    if(primes[p] > fsq_root){
      s += 1;
    }

    /*while(v/j){
      while(j < primes.size() && v%primes[j] == 0){
        v /= j;
        s += v;
        v /= primes[j];
        if(primes[j] > fsq_root){
          s += 1;
        }else if(is_prime(primes[j]) && is_prime(v) && v != primes[j]){
          s += primes[j] + M[v-1];
        }else{
          s += M[v-1]; 
        }
      }
      ++j;
    }*/
  }else{
    s++;
  }

  if(s == i + 1){
    primes.push_back(i);
  }

  return M[i-1] = s;

  /*
  while(!primes.empty() && j < primes.size() && v%primes[j] != 0 && primes[j] <= fsq_root){
    ++j;
  }

  //printf("%d\n", j);

  if(!primes.empty()){

    v /= primes[j];
    if(primes[j] > fsq_root){
      s += 1;
    }else if(is_prime(primes[j]) && is_prime(v) && v != primes[j]){
      s += primes[j] + M[v-1];
    }else{
      s += M[v-1]; 
    }
  }else{
    s++;
  }

  if(s == i + 1){
    primes.push_back(i);
  }

  M[i-1] = s;
  return s;*/
}

int main(int argc, char const *argv[])
{
    int N = 1000;

    M[0] = 1;
    //MSET[0].insert(1);  

    cin >> N;
    while(N != 0){

        long long sum = 0;
        for (int i = N; i <= N; ++i)
        {
          if(M[i-1] > 0){
            sum += M[i-1];
          }else{
            int s = SMLCM2(i);
            sum += s;
            //printf("s%d:%d\n",i, s); 
            M[i-1] = s;
          }
        }
        
        /*for (int i = 0; i < primes.size(); ++i)
        {
          printf("%d ",primes[i]);
        }
        printf("\n");
  */
    
        /*printf("{");
        for (int i = 0; i < MAX - 1; ++i)
        {
          printf("%d,", M[i]);
        }
        printf("%d}", M[MAX - 1]);
        
        return 0;*/

        printf("%lld\n", sum);
    
        cin >> N;
    }
    
    return 0;
}
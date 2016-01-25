#include "stdio.h"
#include "iostream"
#include <cstdlib>

#include <map>

#include <cmath>
#include <algorithm>
#include <vector>
#include <set>

#define INF 999999999

struct point
{
  point(){}
  point(int x, int y): x(x),y(y){ }
  int x;
  int y;
};

#define is_up_right(i,f,v) (i.x < v.x && f.x > v.x && i.y > v.y && f.y < v.y)
#define is_down_right(i,f,v) (i.x <= v.x && f.x >= v.x && i.y == v.y && f.y == v.y)
#define is_up(i,f,v) (i.x == v.x && f.x == v.x && i.y >= v.y && f.y >= v.y)

#define up(p, j) (point(p.x, p.y - j))
#define down(p, j) (point(p.x, p.y + j))
#define up_left(p, i, j) (point(p.x - i, p.y))
#define up_right(p, i, j) (point(p.x + i, p.y - j))
#define down_left(p, i, j) (point(p.x - i, p.y + j))
#define down_right(p, i, j) (point(p.x + i, p.y))

/*hex[0] = up(center, mov);
      hex[1] = down(center, mov);
      hex[2] = up_left(center, mov, mov);
      hex[3] = up_right(center, mov, mov);
      hex[4] = down_left(center, mov, mov);
      hex[5] = down_right(center, mov, mov);*/

#define is_at_border(hex, p) (is_up(hex[5], hex[3],p) || is_up(hex[4],hex[2],p) || is_down_right(hex[0],hex[3],p) || is_down_right(hex[4],hex[2],p) || is_up_right(hex[2], hex[0],p) || is_up_right(hex[1],hex[5],p))

#define printp(p) (printf("p = (%d,%d)\n", p.x, p.y))

#define compute_cells(n) (n + n*(n-1) - ((n-1)*(n+1)/4))

#define MAX 100000

using namespace std;

int main(int argc, char const *argv[])
{
    int T, N, c = 0;
    point points[MAX];


    scanf("%d", &T);
    while(T--){
      scanf("%d", &N);
    
      int most_left = INF;
      int most_right = -INF;
      int most_up = INF;
      int most_down = -INF;
      for (int i = 0; i < N; ++i)
      {
        int x, y;
        scanf("%d %d", &x, &y);
        most_right = std::max(most_right, x);
        most_left = std::min(most_left, x);
        most_up = std::min(most_up, y);
        most_down = std::max(most_down, y);
        points[i].x = x;
        points[i].y = y;
      }

      //printf("%d,%d,%d,%d\n", most_left, most_right, most_up, most_down);
      int diag = std::max(abs((most_left - 1) - (most_right + 1)), abs((most_up - 1) - (most_down + 1))) - 1;
      
      // center
      point center;
      center.x = (most_left + most_right)/2;
      center.y = (most_down + most_up)/2;

      point hex[6];

      if(diag % 2 == 0)
        diag++;

      int mov = (diag+1)/2;
      hex[0] = up(center, mov);
      hex[1] = down(center, mov);
      hex[2] = up_left(center, mov, mov);
      hex[3] = up_right(center, mov, mov);
      hex[4] = down_left(center, mov, mov);
      hex[5] = down_right(center, mov, mov);

      bool atborder = false;
      for (int i = 0; i < N; ++i)
      {
        //printp(points[i]);
        atborder = atborder || is_at_border(hex,points[i]);
      }

      /*for (int i = 0; i < 6; ++i)
      {
        printp(hex[i]);
      }*/

      //printf("c = (%d,%d)\n", center.x, center.y);

      //printf("d = (%d,%d, %d, %d)\n", most_left, most_right, most_up, most_down);
    
      diag += atborder;

      if(diag % 2 == 0)
        diag++;

      printf("Case %d: %lld\n",  ++c, compute_cells(diag));
    }
    
    return 0;
}
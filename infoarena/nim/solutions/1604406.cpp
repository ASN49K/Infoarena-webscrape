#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
   freopen("nim.in", "r", stdin);
   freopen("nim.out", "w", stdout);

   int n, t, x, sum;
   scanf("%d\n", &t);
   for (int i = 1; i <= t; ++i){
      scanf("%d\n", &n);
      sum = 0;
      for (int j = 1; j <= n; ++j){
         scanf("%d ", &x);
         sum ^= x;
      }
      if (sum)
         printf("DA\n");
      else
         printf("NU\n");
   }


   return 0;
}

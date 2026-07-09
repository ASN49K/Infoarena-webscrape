#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);

     int T;

     scanf("%d",&T);

     while (T--)
     {
         int X,Sol = 0;
         scanf("%d",&X);

         while (X--)
         {
             int Y;
             scanf("%d",&Y);
             Sol ^= Y;
         }

         if (Sol)
            printf("DA\n");
       else
            printf("NU\n");
     }

  return 0;
}



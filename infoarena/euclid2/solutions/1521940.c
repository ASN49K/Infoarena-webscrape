#include <stdio.h>
#include <stdlib.h>
int cmmdc (int a, int b)
{
    if (!b) return a;
    if (a>b) return cmmdc(a-b,b);
       else return cmmdc(a,b-a);
}
int main()
{
    int a,b,t;
    freopen("euclid2","r",stdin);
    freopen("euclid2","w",stdout);

     for (scanf("%d", t); t; t--)
     {
         scanf("%d %d", &a, &b);
         printf("%d\n", cmmdc(a,b));
     }
    return 0;
}

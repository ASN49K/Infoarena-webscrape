#include <stdio.h>
int cmmdc(int a, int b)
{
    int r=a%b;
    while(r)
    {
            a=b;
            b=r;
            r=a%b;
    }
    return b;
}

int main ()
{
     int T, a, b, i;
     freopen("euclid2.in", "r", stdin);
     freopen("euclid2.out", "w", stdout);
     scanf("%d",&T);
     for(i=0; i<T; i++)
     {
              scanf("%d%d", &a, &b);
              printf("%d\n", cmmdc(a,b));
     }
     return 0;
}

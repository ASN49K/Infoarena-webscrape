#include <stdio.h>
#include <stdlib.h>
int cmmdc(int a,int b)
{
    int r;
    r=a%b;
    while(r){a=b;b=r;r=a%b;}
    return b;
}

int main()
{
    int T,a,b;
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d",&T);
    for(;T;--T)
    {
      scanf("%d %d",&a,&b);
      printf("%d\n",cmmdc(a,b));
    }
    return 0;
}

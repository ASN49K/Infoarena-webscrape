#include <stdio.h>
#include <stdlib.h>
int cmmdc(int a,int b)
{
    while(a!=b)
        if(a>b)a=a-b;
        else b=b-a;
    return a;
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

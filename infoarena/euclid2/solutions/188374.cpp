#include <stdio.h>
int a,b,t;
int euclid (int a,int b)
{
    int r;
    do
    {
      r=a%b;
      a=b;
      b=r;
    }
    while (r);
    return a;    
}
int main ()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int r,i;
    scanf("%d",&t);
    for (i=1; i<=t; ++i)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",euclid(a,b));
    }
    return 0;
}
    

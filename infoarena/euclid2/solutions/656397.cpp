#include <stdio.h>
int n,x,y;
int euclid(int a , int b)
{
    while(a!=b)
     if(a>b)
      a=a-b;
     else
      b=b-a;

   return a;
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
     {
         scanf("%d %d",&x,&y);
         printf("%d\n",euclid(x,y));
     }
    return 0;
}

#include <stdio.h>
int n,x,y;
int euclid(int a , int b)
{
    int r=0;
   while(b!=0)
    {
      r = a % b;
      a = b;
      b = r;
    }

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

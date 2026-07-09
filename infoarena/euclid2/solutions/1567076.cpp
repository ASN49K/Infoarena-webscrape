#include <iostream>
#include <stdio.h>

using namespace std;

  int euclid(int x,int y)
{
  int r;
  while(y)
     {
      r=x%y;
      x=y;
      y=r;
     }
  return x;
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

      int n,a,b;
        scanf("%d",&n);

      for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            printf("%d\n",euclid(a,b));
        }
}

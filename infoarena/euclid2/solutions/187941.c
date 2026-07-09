#include <stdio.h>

long cmmdc(long x,long y)
{
 long r;
 if(y==0)
  return x;
 r=x%y;
 while(r)
  {
   x=y;
   y=r;
   r=x%y;
  }
 return y;
}

int main()
{
 long n,i,x,y;
 freopen("euclid2.in","r",stdin);
 freopen("euclid2.out","w",stdout);
 scanf("%d",&n);
 for(i=1;i<=n;i++)
  {
   scanf("%d %d",&x,&y); 
   printf("%d\n",cmmdc(x,y));
  }
 return 0;
}

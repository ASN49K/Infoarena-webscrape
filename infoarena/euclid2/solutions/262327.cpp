#include <stdio.h>
int cmmdc(int a,int b)
{
int i,max=0;
if (a<b)
{
for (i=2; i*i<=a; i++)
  if (a%i==0 && b%i==0)
  max=i;
  }
  else
  {
  for (i=2; i*i<=b; i++)
   if (a%i==0 && b%i==0)
   max=i;
  }
  return max;
}
int main()
{
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
int t,i,a,b;
scanf("%d",&t);
for (i=1; i<=t; i++)
{
scanf("%d%d",&a,&b);
printf("%d\n",cmmdc(a,b));
}
return 0;
}
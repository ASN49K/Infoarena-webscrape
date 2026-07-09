#include<stdio.h>
using namespace std;
int main()
{int T,a,b,i=1;
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
scanf("%d",&T);
for(i=1;i<=T;i++)
  {scanf("%d%d",&a,&b);
   while(b)
      {int r=a%b;
       a=b;
       b=r;}
  printf("%d\n",a);}
return 0;}

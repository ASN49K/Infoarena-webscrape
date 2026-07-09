#include<stdio.h>

int main()
{
int a,b,c,T;
int i;

freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);

scanf("%d",&T);

for( i=1; i<=T; i++ )
   {
   scanf("%d%d",&a,&b);
   while( b>0 )
      {
      c = b;
      b = a%b;
      a = c;
      }
   printf("%d\n",a);
   }

return 0;
}
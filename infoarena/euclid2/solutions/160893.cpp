#include<stdio.h>

long a,b,r,i,t;

void read()
{
for(i=1;i<=t;i++)
   {
   scanf("%ld %ld",&a,&b);

   while(b>=1)
	 {
	 r=a%b;
	 a=b;
	 b=r;
	 }

   printf("%ld\n",a);
   }
}
int main()
{
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);

scanf("%ld",&t);
read();


fcloseall();
return 0;
}
#include <stdio.h>
int main()
{
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
long T,a,b,cmmdc,r,i;
scanf("%ld",&T);
for(i=1;i<=T;i++)
   {
	scanf("%ld%ld",&a,&b);
	while(b!=0)
		{
		     r=a%b;
		     a=b;
		     b=r;
		}
	printf("%ld\n",a);
   }
return 0;
}
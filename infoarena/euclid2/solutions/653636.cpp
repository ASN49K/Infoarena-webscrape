#include<stdio.h>
using namespace std;
int a,b,r,i10,t10;
int main()
{
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
scanf("%d",&t10);
for(i10=1;i10<=t10;i10++)
{
	scanf("%d",&a);
	scanf("%d",&b);
	while(b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	printf("%d\n",a);
}
return 0;
}
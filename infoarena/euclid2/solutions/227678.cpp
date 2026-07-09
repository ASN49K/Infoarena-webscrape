#include <stdio.h>
int cmmdc(int a,int b)
{
	int r;
	r=a%b;
	while(b)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return a;
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
		printf("%d",cmmdc(a,b));
	}
	return 0;
}
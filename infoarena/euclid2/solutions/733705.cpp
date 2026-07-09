#include<stdio.h>
long a,b;
int i,n,x;
int cmmdc (long x,long y)
{
	int r;
	do
	{
		r=x%y;
		x=y;
		y=r;
	}while(r>0);
	return x;
}
int main ()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		x=cmmdc(a,b);
		printf("%d\n",x);
	}
	return 0;
}
#include<stdio.h>
int a,b,i,n;
int rockshox(int a, int b)
{
	if(!b)
		return a;
	else
		return rockshox(b,a%b);
}
int main(void)
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	scanf("%d%d",&a,&b);
	printf("%d",rockshox(a,b));}
	return 0;
}
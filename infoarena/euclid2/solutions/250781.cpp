#include<stdio.h>
void euclid (int &a, int &b)
{
	int r;
	while (b)
	{
		r=a%b;
		a=b;
		b=r;
	}
}
void citire()
{
	int n;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&n);
	for (int i=1; i<=n; ++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		euclid(a,b);
		printf("%d\n",a);
	}
}
int main()
{
	citire();
	return 0;
}

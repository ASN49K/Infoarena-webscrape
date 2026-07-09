#include <cstdio>

int n,a,b;

int cmmdc(int a,int b);

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",cmmdc(a,b));
	}
	return 0;
}

int cmmdc(int a,int b)
{
	int r,d,i;
	if (a>b) d=a,i=b;
	else d=b,i=a;
	while (i)
	{
		r=d%i;
		d=i;
		i=r;
	}
	return d;
}

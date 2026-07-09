#include<cstdio>

int cmmdc(int a,int b)
{
	int r;
	while(b)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int t,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",cmmdc(a,b));
	}
	return 0;
}

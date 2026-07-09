#include<stdio.h>

int cmmdc(int x,int y)
{
	while(y)
	{
		int p=y;
		y=x%y;
		x=p;
	}
	return x;
}

int main()
{
	int n;
	int a,b;
	
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",cmmdc(a,b));
	}
	
	return 0;
}
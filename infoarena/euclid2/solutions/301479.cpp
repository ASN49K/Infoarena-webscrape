#include<stdio.h>

int cmmdc(int x,int y)
{
	int aux;
	while(y)
	{
		aux=x%y;
		x=y;
		y=aux;
	}
	return x;
}

int main()
{
	int n;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int a,b;

	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",cmmdc(a,b));
	}
	
	return 0;
}
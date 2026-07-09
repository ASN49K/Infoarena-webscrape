#include <stdio.h>

int a,b,T,i;

int cmmdc(int a,int b)
{
	int r=-1;
	while(r!=0)
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

	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",cmmdc(a,b));
	}

	return 0;
}

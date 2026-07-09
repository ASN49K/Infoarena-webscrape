#include<stdio.h>

int N,i,x,y;

int cmmdc(int a,int b)
{
	int r=(a%b);
	while (r)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	
	scanf("%d",&N);
	
	for (i=1;i<=N;++i)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",cmmdc(x,y));
	}
}

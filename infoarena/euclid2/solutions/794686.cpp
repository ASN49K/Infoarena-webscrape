#include<stdio.h>
int n,i,x,y;

int euclid(int a, int b)
{
	int c=1;
	while(c!=0)
	{
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",euclid(x,y));
	}
	return 0;
}
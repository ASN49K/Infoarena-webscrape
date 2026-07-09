# include <stdio.h>
int i,n,x,y;
int euclid(int a,int b)
{
	int c;
	while (b)
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
	scanf("%d\n",&n);
	for (i=1; i<=n; i++)
	{
		scanf("%d %d\n",&x,&y);
		printf("%d\n",euclid(x,y));
	}
	return 0;
}
#include<cstdio>
int a,b,c,T,i;
int euclid(int a,int b)
{
	int c;
	while(b)
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
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d %d",&a,&b);
		printf("%d",euclid(a,b));
		printf("\n");
	}
	return 0;
}

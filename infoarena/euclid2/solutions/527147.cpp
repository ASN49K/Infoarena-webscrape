#include<stdio.h>

int i,t,n,m;

int euclid(int a,int b)
{
	if (b==0) return a;
	return euclid(b,a%b);
}

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&t);
	
	for (i=1;i<=t;i++)
	{
	scanf("%d%d",&n,&m);
	printf("%d\n",euclid(n,m));
	}
	
	return 0;
}

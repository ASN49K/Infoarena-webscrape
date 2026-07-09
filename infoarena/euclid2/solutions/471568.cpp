#include<cstdio>

int i,n,a,b;

int euclid(int x , int y)
{
	if (!y) return x;
	
	return euclid ( y , x%y);
	
}

int main()
{
	
	freopen("euclid.in","r",stdin);
	freopen("eculid.out","w",stdout);
	
	scanf("%d", &n);
	
	for (i=1;i<=n;i++)
	{
		scanf("%d%d", &a , &b );
		printf("%d\n", euclid(a,b));
	}
	
	
	
	return 0;
}


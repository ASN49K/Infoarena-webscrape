#include <cstdio>

int main()
{
	int j;
	int x;
	int d,i,r;
	
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	
	scanf("%d",&x);
	
	for ( j = 1; j <= x; j++)
	{
		scanf("%d%d",&d,&i);
		
		r = d % i;
		
		while(r)
		{
			d = i;
			i = r;
			r = d % i;
		}
		
		printf("%d\n",i);
	}
	
	return 0;
}
#include <cstdio>

int main()
{
	freopen ("euclid2.in","r",stdin);
	freopen ("euclid2.out","w",stdout);
	int t;
	scanf("%d",&t);
	int x,y;
	while (t--)
	{
		scanf("%d%d",&x,&y);
		while (x&&y)
			if (x>y)
				x%=y;
			else
				y%=x;
		if (x)
			printf("%d\n",x);
		else
			printf("%d\n",y);
	}
	return 0;
}

#include <cstdio>
int main()
{
	int t,x,y,z;
	
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d %d",&x,&y);
		if (x<y) z=x,x=y,y=z;
		z=x%y;
		while (z!=0)
			x=y,y=z,z=x%y;
		printf("%d\n",y);
	}
return 0;
}
			
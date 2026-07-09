#include <stdio.h>
int t,n;
int main()
{
	freopen("nim.in","r",stdin);
	freopen("nim.out","w",stdout);
	scanf("%d",&t);
	int i,x,y;
	while (t--)
	{
		x=0;
		scanf("%d",&n);
		for (i=1; i<=n; i++)
			scanf("%d",&y),x^=y;
		if (x)
			printf("DA\n");
		else
			printf("NU\n");
	}
	return 0;
}

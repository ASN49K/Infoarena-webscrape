#include <stdio.h>

int t,a,b,c;

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&t);
	while (t)
	{
		t--;
		scanf("%d %d",&a,&b);
		while (b)
		{
			c=a % b;
			a=b;
			b=c;
		}
		printf("%d\n",a);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
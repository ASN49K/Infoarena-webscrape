#include <stdio.h>
long a,b,c,i,t;

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	for (i=0; i<t; i++)
	{
		scanf("%ld %ld",&a,&b);
		while (b!=0)
		{
			c=a%b;
			a=b;
			b=c;
		}
		printf("%ld\n",a);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

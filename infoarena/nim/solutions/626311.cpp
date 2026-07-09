#include<stdio.h>
long n,m,i,j,x,a;
int main()
{
	freopen("nim.in","r",stdin);
	freopen("nim.out","w",stdout);
	scanf("%ld",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%ld",&m);
		x=0;
		for(j=1;j<=m;++j)
		{
			scanf("%ld",&a);
			x^=a;
		}
		if(x)printf("DA\n");
		else printf("NU\n");
	}
	return 0;
}
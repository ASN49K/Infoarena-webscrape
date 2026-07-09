#include<stdio.h>

long t,i,j,n,nr,nri;
int main()
{
	freopen("nim.in","r",stdin);
	freopen("nim.out","w",stdout);
	scanf("%ld",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%ld",&n);
		nri=0;
		for(j=1;j<=n;j++)
		{
			scanf("%ld",&nr);
			nri^=nr;
		}
		if(nri==0) printf("NU\n");
		else printf("DA\n");
	}
	return 0;
}

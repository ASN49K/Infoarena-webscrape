#include<stdio.h>
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	long n,m;
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%ld",&n);
		scanf("%ld",&m);
		while(n!=0 && m!=0)
		{
			if(n>m)
				n=n%m;
			else
				m=m%n;
		}
		if(m==0)
		printf("%ld\n",n);
		else
			printf("%ld\n",m);
	}
	return 0;
}	
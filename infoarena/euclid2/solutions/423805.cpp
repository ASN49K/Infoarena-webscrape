#include<cstdio>

int main()
{
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);

int s,t,x,y;

scanf("%ld",&t);
for(long i=1;i<=t;i++)
	{
	scanf("%ld%ld",&x,&y);
	
	while(y)
		{
		s=x;
		x=y;
		y=s%y;
		}	
		
	printf("%ld\n",x);
	}

return 0;
}

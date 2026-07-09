#include<stdio.h>
#include<math.h>
long a,b,r,n;
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%ld",&n);
	for(i=1;i<=n;++i)
	{ 
	scanf("%ld%ld",&a,&b);
	while(b!=0)
	      {
	      r=a%b;
	      a=b;
	      b=r;
	      }
	printf("%ld\n",a);
	}
	return 0;
}

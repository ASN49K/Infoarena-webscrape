#include<stdio.h>
#include<stdlib.h>

int cmmdc( int a, int b)
{
	
	if( !b) return a;
	return cmmdc(b,a%b);
}
		
int main()
{
	int a,b,n;
	freopen ("euclid.in","r",stdin );
	freopen ("euclid.out","w",stdout);
	scanf( "%d",&n);
	for( int i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			printf("%d\n",cmmdc(a,b));
	}
	\
	return 0;
}

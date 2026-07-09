#include <stdio.h>

int n;
int cmmdc (int a,int b)
{
	if (b == 0)
		return a;
	return cmmdc(b,a%b);
	
}

int main ()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	
	scanf("%d",&n);
	for (int i = 1;i <= n; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",cmmdc(a,b));
		
	}
	
	
	return 0;
}

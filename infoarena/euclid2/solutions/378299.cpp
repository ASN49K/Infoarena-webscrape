#include<stdio.h>
int n,x,y,i;
int cmmdc(int a, int b)
{
	while(a%b!=0)
	{
		a=b;
		b=a%b;		
	}
	return b;
}
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d %d",&x,&y);
		printf("%d\n",cmmdc(x,y));
	}
	return 0;
}

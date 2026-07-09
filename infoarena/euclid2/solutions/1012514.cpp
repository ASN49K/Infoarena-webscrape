#include<stdio.h>

int cmmdc(int a,int b)
{
	if(!b) return a;
	else
		return cmmdc(b,a- ( (a/b) * b ) );
}

int main()
{
	int n,x,y;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	
	scanf("%d",&n);

	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",cmmdc(x,y));
	}
}
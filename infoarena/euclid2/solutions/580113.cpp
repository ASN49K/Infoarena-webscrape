#include<stdio.h>

int n,x,y;

int cmmdc(int a, int b)
{
    if (b == 0)
       return a;
    else
       return cmmdc(b, a%b);
}

int main()
{
	int i;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&n);
	for (i=1; i<=n; i++)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",cmmdc(x,y));
	}
	return 0;
}

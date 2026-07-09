#include<stdio.h>
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int a,b;
	scanf("%d%d",&a,&b);
	while(a!=b)
	{
		if(a>b)
			a-=b;
		else
			b-=a;
	}
	printf("%d\n",a);
	return 0;
}

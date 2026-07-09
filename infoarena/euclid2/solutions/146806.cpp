#include<stdio.h>

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int a,b;
	scanf("%d%d",&a,&b);
	if(a==b)
		printf("%d\n",a);
	while(a!=b)
	{
		if(a<b)
		{	b=b-a;
		continue;}
		if(a>b)
		{
			a=a-b;
			continue;
		}
	}
	printf("%d\n",a);
	return 0;
}
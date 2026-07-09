#include<stdio.h>
int a,b,T,x,y,p,i;
int main()
{
	scanf("%d",&T);
	p=T;
	while(p>0)
	{
		scanf("%d ",&a);
                scanf("%d",&b);
		p=p-1;
	}
	for(i=1;i<=T;i++)
	{
		a=x;
		b=y;
		while(x!=y)
		{
			if(x>y)
			{
				x=x-y;
			}
			if(x<y)
			{
				y=y-x;
			}
		}
		if(x==y)
		{
			printf("%d",x);
		}
	}
	return 0;
}

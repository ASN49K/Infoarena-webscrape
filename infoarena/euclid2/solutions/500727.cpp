#include<stdio.h>
int euclid(int a,int b)
{
	int r;
	if(a>=b)
	{
		while(b)
		{
			r=a%b;
			a=b;
			b=r;
		}	
	return a;	
	}
	else
	{
		while(a)
		{
			r=b%a;
			b=a;
			a=r;
		}
	return b;	
	}	
}

int p=1,a,b,cmmdc;
int main()
{
	freopen("euclid2.in","r",stdin); 
	freopen("euclid2.out","w",stdout); 
	int i, t;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",euclid(a,b));
	}	
	return 0;
}

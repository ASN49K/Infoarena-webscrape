#include<stdio.h>


int euclid(int a,int b)
{
if(b==0) return a;
else return euclid(b,a%b);
}


int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	
	int m,n,t;
	scanf("%d\n",&t);
	for(int i=1;i<=t;i++)
	{
	scanf("%d %d",&m,&n);
	printf("%d\n",euclid(m,n));
	}
	
return 0;
}
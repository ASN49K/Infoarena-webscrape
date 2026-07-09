/*
    Keep It Simple!
*/

#include<stdio.h>

int n;

int cmmdc(int a,int b)
{
	if(!b) 
		return a;
	else
		return cmmdc(b,a%b);
}
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	
	int a,b;
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",cmmdc(a,b));
	}
}

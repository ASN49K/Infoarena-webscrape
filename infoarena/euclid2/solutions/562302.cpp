#include<iostream.h>
#include<stdio.h>
int cmmdc(int a, int b)
{
	if(b==0)
		return a;
	return cmmdc(b,a%b);
}
 int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int a,b,T,i;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d",&a);
		scanf("%d",&b);
		printf("%d\n",cmmdc(a,b));
	}
	return 0;
 }

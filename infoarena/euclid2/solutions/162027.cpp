#include<stdio.h>
int cmmdc(int a,int b)
{
	if(a%b==0)
		return b;
	return cmmdc(b,a%b);
}
int main()
{
	int a,b,t,i;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&t);
	for(i=0; i<t; i++)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",cmmdc(a,b));
	}
	return 0;
}

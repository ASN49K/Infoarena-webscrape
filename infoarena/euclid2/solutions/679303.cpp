#include<stdio.h>
int T,a,b;
void deschidere()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
}
int cmmdc(int a,int b)
{
	if((!a)||(!b))
		return a+b;
	else
		if(a>b)
			return cmmdc(a%b,b);
		else
			return cmmdc(a,b%a);
}
void citire()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",cmmdc(a,b));
	}
}
int main()
{
	deschidere();
	citire();
	return 0;
}
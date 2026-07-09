#include<stdio.h>
int T,a,b;
void deschidere()
{
	freopen("euclid.in","r",stdin);
	freopen("euclid.out","w",stdout);
}
int cmmdc(int a,int b)
{
	if((!a)||(!b))
		return a+b;
	else
		if(a>b)
			return(a%b,b);
		else
			return(a,b%a);
}
void citire()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		printf("%d",cmmdc(a,b));
	}
}
int main()
{
	deschidere();
	return 0;
}
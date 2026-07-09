//Problema algoritmul lui Euclid - Infoarena

#include<stdio.h>

int t,a,b,i;

int cmmdc(int,int);

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);

	scanf("%d",&t);

	for(i=1;i<=t;i++)
	{
		scanf("%d %d",&a,&b);

		printf("%d\n",cmmdc(a,b));
	}

	return 0;
}

int cmmdc(int a,int b)
{
	if(b)
		return cmmdc(b,a%b);
	else
		return a;
}
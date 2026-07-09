#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int T,a,b,i,r;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d%d",&a,&b);
		while(a%b)
		{
			r=a%b;
			a=b;
			b=r;
		}
		printf("%d\n",b);
	}
	return 0;
}

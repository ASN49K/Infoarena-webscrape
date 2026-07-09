#include<iostream>
#include<cstdio>
using namespace std;
long int a,b,r,i,n;
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		while (b)
		{
			r=a%b;
			a=b;
			b=r;
		}
		printf("%d\n",a);
	}
	return 0;
}

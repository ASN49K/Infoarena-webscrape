#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a,b,t,r;
	freopen ("euclid2.in","r",stdin);
	freopen ("euclid2.out","w",stdout);
	scanf("%d", &t);
	for(;t;t--)
	{
		scanf("%d%d",&a,&b);
		while(b)
		{ 
			r=a%b;
			a=b;
			b=r;
		}
		printf("%d\n",a);
		
	}
	return 0;
	}
	


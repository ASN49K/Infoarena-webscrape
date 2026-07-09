#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int T,a,b,r;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&T);
	for(;T;T--)
	{
		scanf ("%d%d",&a,&b);
		while(b)
		{
			r = a%b;
			a = b;
			b = r;
		}
		printf("%d\n",a);
	}
	
	return 0;
}
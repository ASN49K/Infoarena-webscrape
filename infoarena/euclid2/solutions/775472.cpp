#include <stdio.h>

using namespace std;

int main()
{
	int i,a,b,T;
	
	freopen ("euclid2.in","r",stdin);
	freopen ("euclid2.out","w",stdout);
	
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%d%d",&a,&b);
		while(a!=b)
			{
				if(a>b)
					a=a-b;
				if(b>a)
					b=b-a;
			}
			printf("%d\n",a);
	}
	
	return 0;
}
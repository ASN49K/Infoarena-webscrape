#include <stdio.h>
#include<iostream.h>

using namespace std;

int main()
{
	int i,a,b,T,c;
	
	freopen ("euclid2.in","r",stdin);
	freopen ("euclid2.out","w",stdout);
	
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%d%d",&a,&b);
		while(b!=0)
			{
				c=a%b;
				a=b;
				b=c;
			}
			printf("%d\n",a);
	}
	
	return 0;
}
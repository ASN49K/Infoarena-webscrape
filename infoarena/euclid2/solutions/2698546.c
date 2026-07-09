#include <stdio.h>
#include <stdlib.h>
int euclid(int a,int b)
{
	if(!b)
		return a;
	return euclid(b,a%b);
}
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int n,a,b;
	scanf("%i",&n);
	for(;n;--n)
	{
		scanf("%i%i",&a,&b);
		printf("%i\n",euclid(a,b));
	}
    return 0;
}

#include "stdio.h"
#define in "euclid2.in"
#define out "euclid2.out"

    int a,b,T;

int euclid (int a,int b);
	
void citire()
{
	freopen(in,"r",stdin);
	scanf("%d ",&T);
	for (int i=0;i<T;i++)
	{
		scanf("%d %d",&a,&b);
			printf("%d\n",euclid(a,b));
	}
	fclose(stdin);
}

int euclid (int a,int b)
{
    int t=0;
    while (b!=0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main()
{
	freopen(out,"w",stdout);
	citire();
	fclose(stdout);
	return 0;
}

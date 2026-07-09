#include "stdio.h"
#define in "euclid.in"
#define out "euclid.out"

    int a,b;

void citire()
{
	freopen(in,"r",stdin);
    scanf("%d %d",&a,&b);
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
	citire();
	freopen(out,"w",stdout);
	printf("%d",euclid(a,b));
	fclose(stdout);
	return 0;
}

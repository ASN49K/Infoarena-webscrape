#include <stdio.h>

using namespace std;

int euclid(int a, int b)
{
    int r;
    while( a % b != 0 )
    {
        r = a % b;
        a = b;
        b = r;
    }
    return b;
}

int a,b,n,i;

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",euclid(a,b));
    }
    return 0;
}

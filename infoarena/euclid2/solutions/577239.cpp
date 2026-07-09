#include <cstdio>

using namespace std;

int t, a, b;

void cmmdc()
{
    while (b)
    {
        int r=a%b;
        a=b;
        b=r;
    }
}

int main()
{
    freopen ("euclid2.in","r",stdin);
    freopen ("euclid2.out","w",stdout);
    scanf ("%d ",&t);
    while (t--)
    {
        scanf ("%d %d ",&a,&b);
        cmmdc();
        printf ("%d\n",a);
    }
    return 0;
}

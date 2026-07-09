#include <algorithm>
using namespace std;

int t,a,b;

inline int cmmdc (int a,int b)
{
    int r;

    do
    {
        r=a%b;
        a=b;
        b=r;
    }
    while (r);

    return a;
}


int main ()
{
    freopen ("euclid2.in","r",stdin);
    freopen ("euclid2.out","w",stdout);
    int i;

    scanf ("%d",&t);
    for (i=1; i<=t; ++i)
    {
        scanf ("%d%d",&a,&b);
        printf ("%d\n",cmmdc (a,b));
    }

    return 0;
}

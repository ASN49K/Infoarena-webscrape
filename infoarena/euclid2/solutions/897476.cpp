#include <cstdio>

using namespace std;

int n,i,x,y,r;

int main()
{
    freopen ("euclid2.in","r",stdin);
    freopen ("euclid2.out","w",stdout);

    scanf ("%d",&n);

    for (i=1; i<=n; i++)
    {
        scanf ("%d %d",&x,&y);
        r = x%y;
        while (r)
        {
            x = y;
            y = r;
            r = x%y;
        }
        printf ("%d\n",y);
    }
    return 0;
}

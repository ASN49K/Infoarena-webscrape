#include <cassert>
#include <cstdio>

int main()
{
    int t=0,n=0,i=0,a=0,x=0;

    assert(freopen("nim.in","r",stdin));
    assert(freopen("nim.out","w",stdout));

    assert(scanf("%d",&t));
    while (t>0)
    {
        --t;
        assert(scanf("%d",&n));
        x=0;
        for (i=0; i<n; ++i)
        {
            assert(scanf("%d",&a));
            x^=a;
        }
        if (!x)
            assert(printf("NU\n"));
        else
            assert(printf("DA\n"));
    }

    return 0;
}

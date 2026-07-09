#include <cassert>
#include <cstdio>

const int dim=1026;
int n=0,m=0,v1[dim],v2[dim],sir[dim],d[dim][dim];

int max(int x,int y)
{
    if (x>y)
        return x;
    return y;
}

void read()
{
    int i=0;

    assert(scanf("%d%d",&n,&m));
    for (i=1; i<n+1; ++i)
        assert(scanf("%d",&v1[i]));
    for (i=1; i<m+1; ++i)
        assert(scanf("%d",&v2[i]));
}

int main()
{
    int i=1,j=0,sol=0;

    assert(freopen("cmlsc.in","r",stdin));
    assert(freopen("cmlsc.out","w",stdout));

    read();
    while (i<=n)
    {
        j=1;
        while (j<=m)
        {
            if (v1[i]==v2[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);

            ++j;
        }

        ++i;
    }

    i=n;j=m;
    while (i && j)
    {
        if (v1[i]==v2[j])
        {
            sir[sol++]=v1[i];
            --i;
            --j;
        }
        else if (d[i-1][j]>d[i][j-1])
            --i;
        else
            --j;
    }

    assert(printf("%d\n",sol));
    for (i=sol-1; i>=0; --i)
        assert(printf("%d ",sir[i]));

    return 0;
}

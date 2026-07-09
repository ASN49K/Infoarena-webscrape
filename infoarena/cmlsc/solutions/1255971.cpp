#include <cstdio>

using namespace std;
int a[1028],b[1028],d[1028],c[1024][1024],i,j,r,n,m,q;
int main()
{
    freopen ("cmlsc.in","r",stdin);
    freopen ("cmlsc.out","w",stdout);
    scanf ("%d %d", &n, &m);
    for (i=1;i<=n;i++)
        scanf ("%d", &a[i]);
    for (i=1;i<=m;i++)
        scanf ("%d", &b[i]);
    for (i=1;i<=n;i++)
    {
        if (a[i]==b[1])
        {
        c[i][1]=1;
        for (i=i+1;i<=n;i++)
            c[i][1]=1;
        }
    }
    for (i=1;i<=m;i++)
    {
        if (a[1]==b[i])
        {
        c[1][i]=1;
        for (i=i+1;i<=m;i++)
            c[1][i]=1;
        }
    }
    for (i=2;i<=n;i++)
        for (j=2;j<=m;j++)
        {
            if (a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else
            {
                if (c[i][j-1]<c[i-1][j])
                    q=c[i-1][j];
                else
                    q=c[i][j-1];
                c[i][j]=q;
            }
        }
    printf ("%d\n", c[n][m]);
    i=n;
    j=m;
    while (i>0 && j>0)
    {
        if (a[i]==b[j])
        {
            d[++r]=a[i];
            i--;
            j--;
        }
        else
        {
            if  (c[i-1][j]<c[i][j-1])
                j--;
            else
                i--;
        }
    }
    for (i=r;i>=1;i--)
        printf ("%d ", d[i]);
    return 0;
}

#include <cstdio>

using namespace std;
int i,n,m,j,a[1028],b[1028],c[1056784],d[1028][1028],nr;
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
        for (j=1;j<=m;j++)
        {
            if (a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
            {
                if (d[i-1][j]<d[i][j-1])
                    d[i][j]=d[i][j-1];
                else
                    d[i][j]=d[i-1][j];
            }
        }
    i=n;
    j=m;
    while (i>0  && j>0)
    {
        if (a[i]==b[j])
        {
            c[++nr]=a[i];
            i--;
            j--;
        }
        else if (d[i][j-1]>d[i-1][j])
            j--;
        else
            i--;
    }
    printf ("%d\n", nr);
    for (i=nr;i>=1;i--)
        printf ("%d ", c[i]);
    return 0;
}

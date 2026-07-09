#include <cstdio>
#include <algorithm>
#define Nmax 1025

using namespace std;

int i, j, m , n, k, a[Nmax], b[Nmax], c[Nmax][Nmax], v[Nmax];

int main()
{
    freopen ("cmlsc.in", "r", stdin);
    freopen ("cmlsc.out", "w", stdout);
    scanf ("%d%d", &m, &n);
    for (i=1; i<=m; i++) scanf ("%d", &a[i]);
    for (i=1; i<=n; i++) scanf ("%d", &b[i]);
    for (i=1; i<=m; i++)
    {
        for (j=1; j<=n; j++)
        {
            if (a[i]==b[j])
            {
                c[i][j]=c[i-1][j-1]+1;
            }
            else
            {
                c[i][j]=max(c[i-1][j], c[i][j-1]);
            }
        }
    }
    /*for (i=1; i<=m; i++)
    {
        for (j=1; j<=n; j++)
        {
            printf ("%d ", c[i][j]);
        }
        printf ("\n");
    }*/
    for (i=m; i>=1; i--)
    {
        for (j=n; j>=1; j--)
        {
            if (a[i]==b[j]) v[++k]=a[i],i--,j--;
            else if (c[i][j-1]<c[i-1][j]) i--;
            else j--;
        }
    }
    printf ("%d\n", k);
    for (i=k; i>=1; i--)
    {
        printf ("%d ", v[i]);
    }
}

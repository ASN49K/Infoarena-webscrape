#include <cstdio>
#define Max(a, b) a>b?a:b

using namespace std;

int a[1030], b[1030], n, m, c[1030][1030], lmax, d[1030], l;

void citire()
{
    scanf ("%d %d\n",&n,&m);
    for (int i=1; i<=n; i++)
        scanf ("%d ",&a[i]);
    for (int j=1; j<=m; j++)
        scanf ("%d ",&b[j]);
}


void matrice()
{
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (a[i]==b[j])
                c[i][j] = c[i-1][j-1]+1;
            else
                c[i][j] = Max(c[i][j-1],c[i-1][j]);
}

void afisare()
{
    lmax=c[n][m];
    printf ("%d\n",lmax);
    int i=n, j=m;
    while (i && j)
    {
        if (a[i]==b[j])
        {
            d[l++]=a[i];
            i--; j--;
        }
        else
        {
            if (c[i][j-1]>c[i-1][j])
                j--;
            else
                i--;
        }
    }
}

int main()
{
    freopen ("cmlsc.in","r",stdin);
    freopen ("cmlsc.out","w",stdout);
    citire();
    matrice();
    afisare();
    for (int i=l-1; i>=0; i--)
        printf ("%d ",d[i]);
    printf ("\n");
    return 0;
}

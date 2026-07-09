#include <cstdio>
#include <algorithm>

using namespace std;

int n,m,a[1050],b[1050],d[1050][1050],i,j,x;

void drum (int v, int i, int j)
{
    if (v)
    {
        if (d[i-1][j-1] == v-1)
        {
            drum (v-1,i-1,j-1);
            printf ("%d ",b[j]);
        }
        else if (d[i-1][j] > d[i][j-1]) drum (v,i-1,j);
        else drum (v,i,j-1);
    }
}

int main()
{
    freopen ("cmlsc.in","r",stdin);
    freopen ("cmlsc.out","w",stdout);

    scanf ("%d %d",&n,&m);

    for (i=1; i<=n; i++)
    {
        scanf ("%d",&a[i]);
        d[i][1] = 0;
    }

    for (i=1; i<=m; i++)
    {
        scanf ("%d",&b[i]);
        d[1][i] = 0;
    }

    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
        {
            if (a[i] == b[j]) d[i][j] = d[i-1][j-1] + 1;
            else d[i][j] = max (d[i-1][j],d[i][j-1]);
        }

    printf ("%d\n",d[n][m]);

    x = d[n][m];

    drum (x,n,m);

    printf ("\n");

    return 0;
}

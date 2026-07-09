#include <cstdio>

using namespace std;
int n,m,i,j,d,b[1025],a[1025],lung[1025][1025],sir[1025],x,y;
int main ()
{
    freopen ("cmlsc.in","r",stdin);
    freopen ("cmlsc.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (i=1; i<=n; i++)
    {
        scanf ("%d",&a[i]);
        lung[i][0]=-1;lung[i][m+1]=-1;
    }

    for (j=1; j<=m; j++)
    {
        scanf ("%d",&b[j]);
        lung[0][j]=-1;lung[n+1][j]=-1;
    }

    for (i=1; i<=n; i++)
    {
        if (b[1]==a[i]) lung[i][1]=1;
        else lung[i][1]=lung[i-1][1];
    }
    for (j=1; j<=m; j++)
    {
        if (b[j]==a[1]) lung [1][j]=1;
        else lung[1][j]=lung[1][j-1];
    }
    for (i=2; i<=n; i++)
        for (j=2; j<=m; j++)
        {
            if (a[i]==b[j])
                lung[i][j]=lung[i-1][j-1]+1;
            else
            {
                if (lung[i-1][j]>lung[i][j-1]) x=lung[i-1][j];
                else x=lung[i][j-1];
                lung[i][j]=x;
            }
        }
    printf("%d\n", lung[n][m]);
    x=n;
    y=m;
    while (lung[x][y]!=0)
    {
        if(a[x]==b[y])
        {
            d++;
            sir[d]=a[x];
            x--;
            y--;
        }
        else
        {
            if (lung[x-1][y]>lung[x][y-1]) x--;
            else y--;

        }
    }
    for (i=d; i>=1; i--) printf ("%d ", sir[i]);




    return 0;
}

#include <algorithm>
using namespace std;

#define DIM 1030

int best[DIM][DIM];
int a[DIM],b[DIM];
int n,m,sol,x,y;

void read ()
{
    int i;

    scanf ("%d%d",&n,&m);
    for (i=1; i<=n; ++i)
        scanf ("%d",&a[i]);
    for (i=1; i<=m; ++i)
        scanf ("%d",&b[i]);
}

void print (int x,int y)
{
    if (!x || !y)
        return ;

    if (a[x]==b[y])
    {
        print (x-1,y-1);
        printf ("%d ",a[x]);
        return ;
    }
    if (best[x-1][y]<best[x][y-1])
        print (x,y-1);
    else
        print (x-1,y);
}

void solve ()
{
    int i,j;

    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
        {
            if (a[i]==b[j])
                best[i][j]=best[i-1][j-1]+1;
            else
                best[i][j]=max (best[i-1][j],best[i][j-1]);
            if (best[i][j]>sol)
            {
                sol=best[i][j];
                x=i; y=j;
            }
        }
    printf ("%d\n",sol);
    print (x,y);
}

int main ()
{
    freopen ("cmlsc.in","r",stdin);
    freopen ("cmlsc.out","w",stdout);

    read ();
    solve ();

    return 0;
}

#include <algorithm>
using namespace std;

#define DIM 1030

int best[DIM][DIM];
int a[DIM],b[DIM];
int n,m;

void read ()
{
    int i;

    scanf ("%d%d",&n,&m);
    for (i=1; i<=n; ++i)
        scanf ("%d",&a[i]);
    for (i=1; i<=m; ++i)
        scanf ("%d",&b[i]);
}

void solve ()
{
    int i,j;

    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
            if (a[i]==b[j])
                best[i][j]=best[i-1][j-1]+1;
            else
                best[i][j]=max (best[i-1][j],best[i][j-1]);
    printf ("%d\n",best[n][m]);
}

void print (int val,int x,int y)
{
    if (!val)
        return ;
    if (a[x]==b[y])
    {
        print (val-1,x-1,y-1);
        printf ("%d ",a[x]);
    }
    else if (best[x-1][y]>best[x][y-1])
        print (val,x-1,y);
    else
        print (val,x,y-1);
}

int main ()
{
    freopen ("cmlsc.in","r",stdin);
    freopen ("cmlsc.out","w",stdout);

    read ();
    solve ();
    print (best[n][m],n,m);

    return 0;
}

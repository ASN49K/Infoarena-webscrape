#include <cstdio>

using namespace std;
int i,j,n,m,a[1030],b[1030],kap[1030][1030],kappa,x,y,solutiongg[1030];
int mx(int x,int y)
{
    if (x>y) return x;
    else return y;
}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (i=1; i<=n; ++i)
        scanf("%d",&a[i]);
    for (i=1; i<=m; ++i)
        scanf("%d",&b[i]);
    for (i=1; i<=m; ++i)
        if (a[1]==b[i]) kap[1][i]=1;
        else kap[1][i]=0;
    for (i=2; i<=n; ++i)
        if (b[1]==a[i]) kap[i][1]=1;
        else kap[i][0]=1;
    for (i=2; i<=n; ++i)
        for (j=2; j<=m; ++j)
        {
            if (a[i]==b[j]) kap[i][j]=mx(kap[i-1][j],kap[i][j-1])+1;
            else kap[i][j]=mx(kap[i-1][j],kap[i][j-1]);
            if (kap[i][j]>kappa) kappa=kap[i][j];
        }
    printf("%d\n",kappa);
    x=n;
    y=m;
    while (x>0 && y>0)
    {
        if (a[x]==b[y]) printf("%d ",a[x]),x--,y--;
        else if (kap[x-1][y]>kap[x][y-1]) x--;
        else y--;
    }
    return 0;
}

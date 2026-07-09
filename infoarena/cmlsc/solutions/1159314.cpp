#include <cstdio>

using namespace std;
int maxm(int x, int y)
{
    if(x >= y)
        return x;
    return y;
}
#define MAX 1030
int n,m,a[MAX],b[MAX],mat[MAX][MAX],sol[MAX*MAX],lin,col,val;
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(i=1;i<=m; i++)
        scanf("%d",&b[i]);
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i] == b[j])
                mat[i][j]=mat[i-1][j-1]+1;
            else
                mat[i][j] = maxm(mat[i-1][j],mat[i][j-1]);
    /*for(i=1; i<=n; i++){
        for(j=1; j<=m; j++)
            printf("%d ",mat[i][j]);
        printf("\n");
    }*/
    lin=n; col=m; val=mat[lin][col];
    while(val>0)
    {
        if(a[lin]==b[col] and mat[lin][col]-1 == mat[lin-1][col-1])
        {
            sol[val]=a[lin];
            lin--; col--; val--;
        }
        else if(mat[lin][col]==mat[lin][col-1])
            col--;
        else if(mat[lin][col]==mat[lin-1][col])
            lin--;
    }
    printf("%d\n",mat[n][m]);
    for(i=1; i<=mat[n][m]; i++)
        printf("%d ",sol[i]);
    return 0;
}

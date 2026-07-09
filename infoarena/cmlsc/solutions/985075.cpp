#include <cstdio>
int n,m;
int a[1025],b[1025];
int mat[1025][1025];
int sir[1025];
void gaseste_sir(int x, int y, int l)
{
    if(!x || !y)
        return;
    if(a[x] == b[y])
    {
        sir[l--] = a[x];
        gaseste_sir(x-1,y-1,l);
    }
    else
        if(mat[x-1][y]>mat[x][y-1])
            gaseste_sir(x-1,y,l);
        else
            gaseste_sir(x,y-1,l);
}
int main()
{
    freopen("cmlsc.in","r",stdin);
  freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i =1; i<=n; i++)
        scanf("%d",&a[i]);
    for(int i = 1;i<=m; i++)
        scanf("%d",&b[i]);
    for(int i =1; i<=n; i++)
        for(int j = 1; j<=m; j++)
            if(a[i] == b[j])
                mat[i][j] = mat[i-1][j-1]+1;
            else
                if(mat[i-1][j]>mat[i][j-1])
                    mat[i][j] = mat[i-1][j];
                else
                    mat[i][j] = mat[i][j-1];
    gaseste_sir(n,m,mat[n][m]);
    printf("%d\n",mat[n][m]);
    for(int i = 1; i<=mat[n][m]; i++)
        printf("%d ",sir[i]);
}

#include <fstream>
#include <cstdio>
using namespace std;

ofstream g("cmlsc.out");

long n,n2,v[1025],v2[1025],nr,i,sir[1025],j,x,y,mat[1025][1025][3];
int main()
{
    freopen("cmlsc.in","r",stdin);
    scanf("%ld%ld",&n,&n2);
    for (i=1;i<=n;i++)
        scanf("%ld",&v[i]);
    for (i=1;i<=n2;i++)
        scanf("%ld",&v2[i]);

    for (i=1;i<=n;i++)
        for (j=1;j<=n2;j++)
        {
            mat[i][j][0]=max(mat[i][j][0],mat[i-1][j][0]);
            if (mat[i][j][0]==mat[i-1][j][0])
                mat[i][j][1]=2;
            mat[i][j][0]=max(mat[i][j][0],mat[i][j-1][0]);
            if (mat[i][j][0]==mat[i][j-1][0])
                mat[i][j][1]=3;
            if (v[i]==v2[j])
            {
                mat[i][j][0]=max(mat[i][j][0],mat[i-1][j-1][0]+1);
                if (mat[i][j][0]==mat[i-1][j-1][0]+1)
                {
                    mat[i][j][1]=1;
                    mat[i][j][2]=v[i];
                }
            }
            else
            {
                mat[i][j][0]=max(mat[i][j][0],mat[i-1][j-1][0]);
                if (mat[i][j][0]==mat[i-1][j-1][0])
                    mat[i][j][1]=1;
            }
        }
    g<<mat[n][n2][0]<<'\n';
    x=n;
    y=n2;
    for (i=1;i<=mat[n][n2][0];)
    {
        if (mat[x][y][2]!=0)
        {
            i++;
            nr++;
            sir[nr]=mat[x][y][2];
        }
        if (mat[x][y][1]==1)
        {
            x--;
            y--;
        }
        else if (mat[x][y][1]==2)
            x--;
        else
            y--;
    }
    for (i=mat[n][n2][0];i>=1;i--)
        g<<sir[i]<<' ';
    g.close();
    return 0;
}

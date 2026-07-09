#include <fstream>
#include <fstream>
#include <cstdlib>
using namespace std;
ifstream f("bila.in");
ofstream g("bila.out");
int i,j,n,m,a[25][25],b[25][25],nr,mx,istart,jstart,k;
const int dx[]= {0,1,-1,0}, dy[]= {1,0,0,-1};


void drum (int x, int y, int k)
{
    b[x][y]=k;
    if(x==1||x==n||y==1||y==m)
    {
        for (int ii=1; ii<=n; ii++)
        {
            for (int jj=1; jj<=m; jj++)
            g<<b[ii][jj]<<" ";
            g<<endl;
        }
        g<<endl;
    }
    else
        for(int i=0; i<4; i++)
            if(a[x+dx[i]][y+dy[i]]<a[x][y])
            drum(x+dx[i],y+dy[i],k+1);
        b[x][y]=0;
}
int main()
{
    f>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            f>>a[i][j];
    f>>istart>>jstart;
    drum(istart,jstart,1);
    return 0;
}

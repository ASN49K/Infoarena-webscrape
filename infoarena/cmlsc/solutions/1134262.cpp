#include <fstream>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

#define dim 1050

struct pct
{
    int lung,dir;
};

int a[dim], b[dim];
pct mat[dim][dim];

int caut(int x, int y)
{
    if(x==0 || y==0) return 0;
    if(a[x]==b[y])
    {
        mat[x][y].dir=3; // Stanga-sus
        return (mat[x-1][y-1].lung+1);
    }
    else
    {
        if(mat[x-1][y].lung > mat[x][y-1].lung)
        {
            mat[x][y].dir=1; // Stanga
            return mat[x-1][y].lung;
        }
        else
        {
            mat[x][y].dir=2; // sus
            return mat[x][y-1].lung;
        }
    }
}

int main()
{
    int n,m,i,j,u;
    int c[dim];

    in>>n>>m;
    for(i=1;i<=n;++i) in>>a[i];
    for(i=1;i<=m;++i) in>>b[i];

    for(i=0;i<=m;++i)
        for(j=0;j<=n;++j)
            mat[j][i].lung=caut(j, i);

    /*for(i=0;i<=m;++i)
    {
        for(j=0;j<=n;++j) out<<mat[j][i].lung<<" ";
        out<<"\n";
    }*/

    j=m;
    i=n;
    u=0;
    while(i>0 && j>0)
    {
        if(a[i]==b[j]) c[++u]=a[i];
        //out<<"mat["<<i<<"]["<<j<<"].dir="<<mat[i][j].dir<<"\n";
        if(mat[i][j].dir==1) --i;
        else if(mat[i][j].dir==2) --j;
        else
        {
            --i;
            --j;
        }
    }

    out<<u<<"\n";
    for(i=1;i<=u;++i) out<<c[i]<<" ";

    return 0;
}

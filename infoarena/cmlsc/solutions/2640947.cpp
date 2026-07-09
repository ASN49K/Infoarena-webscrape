#include <fstream>

using namespace std;
int n,m,i,j,x,y,v[1050],w[1050],r[1050],d[1050][1050];
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>n>>m;
    for(i=1; i<=n; i++)
    {
        f>>v[i];
    }
    for(i=1; i<=m; i++)
    {
        f>>w[i];
    }
    for(i=1; i<=n; i++)
    for(j=1; j<=m; j++)
    {
        d[i][j]=max(d[i-1][j],d[i][j-1]);
        if(v[i]==w[j]) d[i][j]=max(d[i][j],d[i-1][j-1]+1);
    }
    g<<d[n][m]<<'\n';
    x=n;
    y=m;
    i=d[n][m];
    while(i)
    {
        if(v[x]==w[y]&&d[x][y]==d[x-1][y-1]+1)
        {
            r[i]=v[x];
            i--;
            x--;
            y--;
        }
        else if(d[x-1][y]==d[x][y]) x--;
        else y--;
    }
    for(i=1; i<=d[n][m]; i++)
    {
        g<<r[i]<<" ";
    }
    f.close(); g.close();
    return 0;
}

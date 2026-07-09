#include <fstream>

using namespace std;
int n,m,i,j,v[1035],w[1035],d[1035][1035];
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>n>>m;
    for(i=1; i<=n; i++) f>>v[i];
    for(i=1; i<=m; i++) f>>w[i];
    for(i=1; i<=n; i++)
    for(j=1; j<=m; j++)
    {
        if(v[i]==w[j]) d[i][j]=d[i-1][j-1]+1;
        d[i][j]=max(d[i][j],d[i-1][j]);
        d[i][j]=max(d[i][j],d[i][j-1]);
    }
    g<<d[n][m]<<'\n';
    for(i=1; i<=n; i++)
    {
        if(d[i][m]>d[i-1][m]) g<<v[i]<<" ";
    }
    f.close(); g.close();
    return 0;
}

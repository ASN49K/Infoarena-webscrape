//darius suge pula
//darius sa te uiti la comentarii
//darius suge pula
#include <fstream>
#include <algorithm>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,v[1050],w[1050],d[1050][1050],fin[1050];

int main()
{
    f>>n>>m;
    for (int i=1; i<=n; ++i) f>>v[i];
    for (int j=1; j<=m; ++j) f>>w[j];
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
        if (v[i]==w[j]) d[i][j]=d[i-1][j-1]+1;
        else d[i][j]=max(d[i-1][j],d[i][j-1]);
    g<<d[n][m]<<'\n';
    int nr=0;
    int i=n;
    int j=m;
    while (i>0 && j>0)
    {
        if (v[i]==w[j])
        {
            ++nr;
            fin[nr]=v[i];
            --i;
            --j;
        }
        else if (d[i-1][j]>d[i][j-1]) --i;
        else --j;
    }
    for (int i=nr; i>=1; --i) g<<fin[i]<<' ';
    g<<'\n';
    f.close();
    g.close();
    return 0;
}
//darius sa citesti primele comentarii

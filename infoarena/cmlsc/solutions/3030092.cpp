#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m;
int a[1025], b[1025];
int v[1025][1025];

void afis(int i, int j)
{
    if(i>0 && j>0)
    {
        if(a[i]==b[j])
        {
            afis(i-1, j-1);
            g<<a[i]<<" ";
        }
        else if(v[i-1][j] >= v[i][j-1])
            afis(i-1, j);
        else
            afis(i, j-1);
    }
}

int main()
{
    f>>n>>m;
    for(int i=1; i<=n; i++)
        f>>a[i];
    for(int j=1; j<=m; j++)
        f>>b[j];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
    {
        if(a[i]==b[j])
            v[i][j]=v[i-1][j-1]+1;
        else
            v[i][j]=max(v[i-1][j], v[i][j-1]);
    }
    g<<v[n][m]<<'\n';
    afis(n, m);
    return 0;
}

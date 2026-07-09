#include <fstream>

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int x[1025],y[1025],c[1025][1025],n,m;
void solve()
{
    int i,j;
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            if (x[i]==y[j]) c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
    fout<<c[n][m]<<'\n';
}
void afis(int i,int j)
{
    if (i>=1&&j>=1)
        if (x[i]!=y[j])
            if (c[i][j-1]>c[i-1][j]) afis(i,j-1);
            else afis(i-1,j);
        else
        {
            afis(i-1,j-1);
            fout<<x[i]<<" ";
        }
}
int main()
{
    fin>>n>>m;
    for (int i=1; i<=n; i++) fin>>x[i];
    for (int i=1; i<=m; i++) fin>>y[i];
    solve();
    afis(n,m);
    return 0;
}

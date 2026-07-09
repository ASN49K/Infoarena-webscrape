#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int x[2001],y[2001],c[2001][2001],n,m;
void solve()
{
    int i,j;
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=m; j++)
        {
            if (x[i]==y[j])c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=max(c[i][j-1],c[i-1][j]);
        }
    }
}
void afis(int i,int j)
{
    if (i>=1&&j>=1)
    {
        if (x[i]!=y[j])
        {
            if (c[i][j-1]>c[i-1][j])afis(i,j-1);
            else
            {
                afis(i-1,j);
            }

        }
        else
        {
            afis(i-1,j-1);
            {
                g<<x[i]<<" ";
            }
        }
    }
}
int main()
{
    int i,j;

    f>>n>>m;

    for (i=1; i<=n; i++)f>>x[i];
    for (j=1; j<=m; j++)f>>y[j];

    solve();
    g<<c[n][m]<<'\n';

    afis(n,m);


    return 0;
}

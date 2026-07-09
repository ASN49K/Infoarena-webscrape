#include <iostream>
#include <fstream>
using namespace std;
ifstream f("ssmc.in");
ofstream g("ssmc.out");
int x[100],y[100],c[100][100],n,m;
void solve()
{
    int i,j;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
    {
        if (x[i]==y[j])
            c[i][j]=c[i-1][j-1]+1;
        c[i][j]=max(c[i][j-1],c[i-1][j]);
    }
}
void afis(int i,int j)
{
    if (i>=1 && j>=1)
        if (x[i]!=y[j])
        if (c[i][j-1]>c[i-1][j])
        afis(i,j-1);
    else afis(i-1,j);
        else afis(i-1,j);
              g<<x[i];
}
int main()
{
    f>>n>>m;
    for (i=1;i<=n;i++)
        f>>x[i];
    for (j=1;j<=m;j++)
        f>>y[j];
solve();
afis(n,m);
    return 0;
}

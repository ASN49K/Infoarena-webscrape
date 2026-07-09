#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1025],b[1025],c[1025][1025];
void tipar(int i,int j)
{
    if(i>=1&&j>=1)
        if(a[i]!=b[j])
    {
        if(c[i-1][j]>c[i][j-1]) tipar(i-1,j);
        else tipar(i,j-1);
    }
    else {
        tipar(i-1,j-1);
        g<<a[i]<<' ';
    }
}
void solve()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        if(a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
    else c[i][j]=max(c[i-1][j],c[i][j-1]);
    g<<c[n][m]<<'\n';
    tipar(n,m);
}

int main()
{
    int i;
   f>>n>>m;
   for(i=1;i<=n;i++) f>>a[i];
   for(i=1;i<=m;i++) f>>b[i];
   solve();
    return 0;
}

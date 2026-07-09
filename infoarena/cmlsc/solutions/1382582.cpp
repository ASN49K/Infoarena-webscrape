#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025][1025],i,n,m,b[1025],c[1025],j,nr,d[1025];
int maximul(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
void solve()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(b[i]==c[j])
            a[i][j]=a[i-1][j-1]+1;
        else
        {
            a[i][j]=maximul(a[i][j-1],a[i-1][j]);
        }
    }
}
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>b[i];
    for(i=1;i<=m;i++)
        f>>c[i];
    solve();
    i=n;j=m;
    while(a[i][j]!=0)
    {
        while(a[i-1][j]==a[i][j])
            i--;
        while(a[i][j-1]==a[i][j])
            j--;
            nr++;
            d[nr]=b[i];
            i--;
            j--;
    }
    g<<nr<<"\n";
    for(i=nr;i>=1;i--)
        g<<d[i]<<" ";
    return 0;
}

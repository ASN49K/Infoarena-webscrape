#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,a[1025],b[1025],x[1025][1025];

void citire()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>a[i];
    for(int i=1;i<=m;i++)
        f>>b[i];
    f.close();
}

int maxx(int a,int b,int c)
{
    int mx=0;
    if(a>mx)
        mx=a;
    if(b>mx)
        mx=b;
    if(c>mx)
        mx=c;
    return mx;
}

void afis(int i,int j)
{
    if(i==1&&j==1||!i||!j)
        return;
    if(a[i]==b[j])
    {
        afis(i-1,j-1);
        g<<a[i]<<' ';
        return;
    }
    if(x[i][j]==x[i-1][j])
    {
        afis(i-1,j);
        return;
    }
    if(x[i][j]==x[i-1][j-1])
    {
        afis(i-1,j-1);
        return;
    }
    afis(i,j-1);
}

int main()
{
    citire();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(a[i]==b[j])
                x[i][j]=x[i-1][j-1]+1;
            else
                x[i][j]=maxx(x[i-1][j-1],x[i-1][j],x[i][j-1]);
    g<<x[n][m]<<'\n';
    afis(n,m);
    return 0;
}

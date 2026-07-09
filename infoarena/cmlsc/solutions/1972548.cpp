#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1030],b[1030],c[1030][1030],i,j;
void afis(int i,int j)
{
    if(i>=1&&j>=1)
        {
    if(a[i]==b[j])
    {
        afis(i-1,j-1);
        g<<a[i]<<" ";

    }
    else if(c[i][j-1]>c[i-1][j]) afis(i,j-1);
    else afis(i-1,j);
    }
}
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++) f>>a[i];
    for(i=1;i<=m;i++) f>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
        else c[i][j]=max(c[i][j-1],c[i-1][j]);
    }
    g<<c[n][m]<<'\n';
    afis(n,m);
    return 0;
}

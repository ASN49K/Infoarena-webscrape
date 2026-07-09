#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int v[1030][1030],i,j,n,m,a[1030],b[1030];
void afis(int i,int j)
{
    if(i>=1&&j>=1)
    {
        if(a[i]==b[j])
        {
            afis(i-1,j-1);
            g<<a[i]<<" ";
        }
        else if(v[i-1][j]>v[i][j-1]) afis(i-1,j);
        else afis(i,j-1);
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
        if(a[i]==b[j])
        {
            v[i][j]=1+v[i-1][j-1];
        }
        else v[i][j]=max(v[i-1][j],v[i][j-1]);
    }
    g<<v[n][m]<<'\n';
    afis(n,m);
    return 0;
}

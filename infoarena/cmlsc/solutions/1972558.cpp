#include <fstream>
#include <iostream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025],b[1025],v[1025][1025];
void afis (int i,int j)
{
    if(i>=1&&j>=1)
    {
        if(a[i]!=b[j])
        {
            if(v[i-1][j]>v[i][j-1])afis(i-1,j);
            else afis(i,j-1);
        }
        else
        {
            afis(i-1,j-1);
            g<<a[i]<<" ";
            cout<<i<<" "<<j<<'\n';
        }
    }
}
int n,m,i,j;
int main()
{
    f>>n>>m;
    for(i=1; i<=n; i++)f>>a[i];
    for(i=1; i<=m; i++)f>>b[i];

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i]==b[j])v[i][j]=v[i-1][j-1]+1;
            else v[i][j]=max(v[i-1][j],v[i][j-1]);

    g<<v[n][m]<<'\n';
    afis(n,m);

    return 0;
}

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025],b[1025],d[1025][1025],v[1025];
int n,m;
void Solve()
{
    int i,j,k=0;
    for(i=1; i<=m; ++i)
    {
        for(j=1; j<=n; ++j)
        {
            if(b[i]==a[j]){d[i][j]=d[i-1][i-1]+1;v[++k]=b[i];}
            else d[i][j]=max(d[i-1][j],d[i][j-1]);

        }

    }
    fout<<d[m][n]<<"\n";
    for(i=1;i<=k;++i)fout<<v[i]<<" ";
}
void citire()
{
    fin>>n>>m;
    int i;
    for(i=1; i<=n; ++i)fin>>a[i];
    for(i=1; i<=m; ++i)fin>>b[i];
    Solve();
}
int main()
{
    citire();
    return 0;
}

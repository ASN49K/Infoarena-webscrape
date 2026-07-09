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
    for(i=1; i<=n; ++i)
    {
        for(j=1; j<=m; ++j)
        {
            if(a[i]==b[j])d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1][j],d[i][j-1]);

        }

    }
    fout<<d[n][m]<<"\n";
     for (i = n, j = m; i; )
        if (a[i] == b[j])
            v[++k] = a[i], --i, --j;
        else if (d[i-1][j] < d[i][j-1])
            --j;
        else
            --i;
            for(i=k;i>=1;--i)fout<<v[i]<<" ";
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

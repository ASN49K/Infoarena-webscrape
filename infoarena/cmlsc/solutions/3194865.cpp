#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
short n,m,a[1025],b[1025],A[1025][1025];
list<short> l;
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
    {
        f>>a[i];
    }
    for(int i=1;i<=m;i++)
        f>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(a[i]==b[j]) {A[i][j]=1+A[i-1][j-1];
        l.push_back(a[i]);}
        else A[i][j]=max(A[i-1][j],A[i][j-1]);
    }
    g<<A[n][m]<<'\n';
    for(auto i:l)
        g<<i<<" ";
    return 0;
}

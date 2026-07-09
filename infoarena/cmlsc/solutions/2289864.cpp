#include <bits/stdc++.h>
using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
const int nmax=1e3+3;
int d[nmax][nmax],v1[nmax],v2[nmax],n,m,k,sol[nmax];
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i) f>>v1[i];
    for(int i=1;i<=m;++i) f>>v2[i];
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            d[i][j]=max(d[i-1][j],d[i][j-1]);
            if(v1[i]==v2[j]) d[i][j]=max(d[i][j],d[i-1][j-1]+1);
        }
    }
    while(n&&m)
    {
        if(v1[n]==v2[m])
        {
            sol[++k]=v1[n];
            --n;
            --m;
            continue;
        }
        if(d[n-1][m]>d[n][m-1]) --n;
        else --m;
    }
    g<<k<<'\n';
    for(int i=k;i;--i) g<<sol[i]<<' ';
    return 0;
}

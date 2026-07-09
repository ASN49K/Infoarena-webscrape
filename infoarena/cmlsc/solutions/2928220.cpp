#include <bits/stdc++.h>
using namespace std;
#define nmax 1100
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int v[nmax],v1[nmax],sir[nmax],dp[nmax][nmax];
int main()
{
    int n,m,k;
    f>>m>>n;
    for(int i=1;i<=m;++i)
        f>>v[i];
    for(int i=1;i<=n;++i)
        f>>v1[i];
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            if(v[i]==v1[j])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    int i=m,j=n;
    while(i){
        if(v[i]==v1[j])sir[++k]=v[i],i--,j--;
        else if(dp[i-1][j]<dp[i][j-1])j--;
        else i--;
    }
    g<<k<<"\n";
    for(int i=k;i>=1;--i)
        g<<sir[i]<<" ";
}

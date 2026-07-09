#include <bits/stdc++.h>
using namespace std ;
ifstream fin("cmlsc.in") ;
ofstream fout("cmlsc.out") ;
const int NM=1025 ;
int v[NM],a[NM],dp[NM][NM],n,m;
vector <int> recon ;
int main()
{
    fin>>n>>m ;
    for(int i=1; i<=n; ++i) fin>>v[i] ;
    for(int i=1; i<=m; ++i) fin>>a[i] ;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
        {
            if(v[i]==a[j]) dp[i][j]=dp[i-1][j-1]+1 ;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]) ;
        }
    fout<<dp[n][m]<<'\n' ;
    int i=n,j=m ;
    while(i>=1 && j>=1)
    {
        if(v[i]==a[j]) recon.push_back(v[i]),i--,j-- ;
        else if(dp[i-1][j]<dp[i][j-1]) j--;
        else i-- ;
    }
    reverse(recon.begin(),recon.end()) ;
    for(auto it: recon) fout<<it<<" " ;
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout("cmlsc.out");
int m,n,v[1001],f[1001],i,j;
long long dp[1001][1001];
int main(){
    fin>>m>>n;
    for(i=1;i<=m;i++)
        fin>>v[i];
    for(i=1;i<=n;i++)
        fin>>f[i];
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if (v[i]==f[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    i=1;
    j=1;
    fout<<dp[m][n]<<"\n";
    while(j<=n && i<=m){
        if(v[i]==f[j]){
            fout<<v[i]<<" ";
            i++;
            j++;
        }
        if(dp[i+1][j]<dp[i][j+1])j++;
        else if(dp[i+1][j]>=dp[i][j+1])i++;
    }
}

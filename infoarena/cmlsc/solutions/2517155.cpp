#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define pb push_back
#define f first
#define sc second
using namespace std;
ll mod=1e9+7,i,j;
ll a[2000],b[2000],dp[2000][2000];
ll n,m;
int main(){
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin>>n>>m;
    for(i=1;i<=n;i++) fin>>a[i];
    for(i=1;i<=m;i++) fin>>b[i];
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i]==b[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    i=n;
    j=m;
    vector<ll>ans;
    while(j>=0||i>=0){
        if(a[i]==b[j]){
            ans.pb(a[i]);
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }
    }
    fout<<ans.size()<<"\n";
    reverse(ans.begin(),ans.end());
    for(unsigned ll k=0;k<ans.size();k++) fout<<ans[k]<<" ";
    return 0;
}

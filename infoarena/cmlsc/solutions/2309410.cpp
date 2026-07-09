#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define N 1025
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int a[N], b[N], dp[N][N];
int main(){
    int n,m,i,j;
    in>>n>>m;
    for(i=1; i<=n; ++i)
        in>>a[i];
    for(i=1; i<=m; ++i)
        in>>b[i];
    for(i=1; i<=n; ++i){
        for(j=1; j<=m; ++j){
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    out<<dp[n][m]<<"\n";
    for(i=1; i<=m; ++i)
        if(dp[n][i]!=dp[n][i-1])
            out<<b[i]<<" ";
    return 0;
}

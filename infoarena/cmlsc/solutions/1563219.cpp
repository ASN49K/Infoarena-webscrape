#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
const char *IN  = "cmlsc.in";
const char *OUT = "cmlsc.out";
const int MAX_SIZE = 1025;

int n,m;
int a[MAX_SIZE];
int b[MAX_SIZE];
int sol[MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE];
int main(void){
    ifstream cin(IN);
    ofstream cout(OUT);
    cin>>n>>m;
    for (int i=1;i<=n;++i) cin>>a[i];
    for (int i=1;i<=m;++i) cin>>b[i];
    // build dp
    memset(dp,0,sizeof dp);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
           dp[i][j] = (a[i]==b[j]) ? dp[i-1][j-1] + 1 : max(dp[i-1][j],dp[i][j-1]);
    cout<<dp[n][m]<<"\n";
    for (int i=n,j=m;i>=1 && j>=1;)
        if (a[i]==b[j]) {
            sol[++sol[0]]=a[i];
            --i;
            --j;
        }
        else
        if (dp[i-1][j] > dp[i][j-1]) --i;
        else --j;
    for (int i=sol[0];i>=1;--i) cout<<sol[i]<<" ";
    return 0;
}

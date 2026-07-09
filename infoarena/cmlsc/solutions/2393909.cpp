#include<bits/stdc++.h>
#define N 1050
using namespace std;

int a[N], b[N], dp[N][N],n,m;
stack<int>S;

int main() {
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    cin>>n>>m;
    for (int i=1; i<=n; ++i) cin>>a[i];
    for (int i=1; i<=m; ++i) cin>>b[i];
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j) {
            if (a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[n][m]<<'\n';
    for (int i=n,j=m; i && j; ) {
        if (a[i]==b[j]) S.push(a[i]), --i,--j;
        else if (dp[i][j-1]>dp[i-1][j]) --j;
        else --i;
    }
    while (S.size()) {
        cout<<S.top()<<" "; S.pop();
    }

    return 0;
}

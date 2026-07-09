#include <bits/stdc++.h>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

short a[1030],b[1030];
int dp[1030][1030];
short c[1030];
int k;
int main() {

    ios_base::sync_with_stdio(false);
    in.tie(NULL);

    int n,m;
    in>>n>>m;
    for (int i=1;i<=n;i++) {
        in>>a[i];
    }
    for (int i=1;i<=m;i++) {
        in>>b[i];
    }

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (a[i]==b[j]) {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    out<<dp[n][m]<<"\n";

    int i=n;
    int j=m;

    while (i>=1 and j>=1) {
        if (a[i]==b[j]) {
            c[++k]=a[i];
            i--;
            j--;
        }
        else {
            if (dp[i][j-1]>=dp[i-1][j])
                j--;
            else
                i--;
        }
    }
    for (int i=k;i>=1;i--) {
        out<<c[i]<<" ";
    }
}
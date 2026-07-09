#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025], b[1025], i, j, n, m, dp[1025][1025];
vector<int>v;
int main()
{
    fin>>n>>m;
    for (i=1; i<=n; i++) {
        fin>>a[i];
    }
    for (i=1; i<=m; i++) {
        fin>>b[i];
    }
    for (i=1; i<=n; i++) {
        for (j=1; j<=m; j++) {
            dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            if (a[i]==b[j]) dp[i][j]=max(dp[i][j], dp[i-1][j-1]+1);
        }
    }
    fout<<dp[n][m]<<'\n';
    i=n, j=m;
    while (dp[i][j]!=0) {
        if (dp[i][j]==dp[i-1][j]) {
            i--;
        }
        else {
            if (dp[i][j]==dp[i][j-1]) {
                j--;
            }
            else {
                i--;
                j--;
                v.push_back(a[i+1]);
            }
        }
    }
    reverse(v.begin(), v.end());
    for (int x:v) fout<<x<<' ';
    return 0;
}

#include <bits/stdc++.h>
#define LUNGIME_MAX 1030

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m;
int a[LUNGIME_MAX],b[LUNGIME_MAX];
int dp[LUNGIME_MAX][LUNGIME_MAX];

void solve(int x, int y) {
    if(x==0||y==0) return;
    if(a[x]==b[y]) {
        solve(x-1,y-1);
    } else {
        if(dp[x-1][y]>dp[x][y-1])
            solve(x-1, y);
        else solve(x, y-1);
    }
    if(a[x]==b[y]) fout<<a[x]<<' ';
}

int main()
{
    fin>>n>>m;

    for(int i=1;i<=n;i++) fin>>a[i];
    for(int j=1;j<=m;j++) fin>>b[j];

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(a[i] == b[j]) {
                dp[i][j] = max(dp[i-1][j-1]+1, max(dp[i-1][j],dp[i][j-1]));
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    fout<<dp[n][m]<<'\n';
    solve(n, m);
    return 0;
}

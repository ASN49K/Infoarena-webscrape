#include <bits/stdc++.h>
#define NMAX 1030

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m;
int a[NMAX],b[NMAX];
int dp[NMAX][NMAX];
stack<int> answer;
int di[]={-1,-1,0},
    dj[]={0,-1,-1};

void solve(int i,int j) {
    if(i==0) return;
    if(a[i]==b[j]) {
        solve(i-1,j-1);
    } else if(dp[i-1][j]<dp[i][j-1]) {
        solve(i,j-1);
    } else {
        solve(i-1,j);
    }
    if(a[i]==b[j]) fout<<a[i]<<' ';
}

int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++) fin>>a[i];
    for(int i=1;i<=m;i++) fin>>b[i];

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(a[i]==b[j]) {
                dp[i][j]=dp[i-1][j-1]+1;
            } else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    fout<<dp[n][m]<<'\n';
    solve(n,m);
    return 0;
}

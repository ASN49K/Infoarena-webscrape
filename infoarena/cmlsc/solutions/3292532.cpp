#include <bits/stdc++.h>
using namespace std;

#define ll long long

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[1030][1030];
int n, m;
vector<int> a, b;

void bfs_reverse(int i, int j){
    if(i==0 || j==0)
        return;

    if(a[i]==b[j]){
        bfs_reverse(i-1,j-1);
        fout<<a[i]<<" ";
    }else{
        if(i>1 && dp[i][j]==dp[i-1][j])
            bfs_reverse(i-1,j);
        else if(j>1 && dp[i][j]==dp[i][j-1])
            bfs_reverse(i,j-1);
    }
}

int main()
{
	ios::sync_with_stdio(false);
	fin.tie(nullptr);

    fin>>n>>m;

    a.resize(n+1);
    b.resize(m+1);

    for(int i=1;i<=n;i++)
        fin>>a[i];

    for(int i=1;i<=m;i++)
        fin>>b[i];

    dp[0][0]=dp[1][0]=dp[0][1]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
    }
    fout<<dp[n][m]<<'\n';

    if(dp[n][m]>0){
        bfs_reverse(n,m);
    }

    return 0;
}

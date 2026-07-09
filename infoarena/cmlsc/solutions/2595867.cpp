#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m;
int numsn[1030], numsm[1030];
int dp[1030][1030];

void dfs(int i, int j);

int main()
{

    fin >> n >> m;

    for(int i = 1; i <= n; ++i) fin >> numsn[i];
    for(int i = 1; i <= m; ++i) fin >> numsm[i];

    for(int i = 1; i <= n; ++i){

        for(int j = 1; j <= m; ++j){
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            if(numsn[i] == numsm[j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }

    }

    fout << dp[n][m] << "\n";

    dfs(n, m);

    return 0;
}

void dfs(int i, int j){
    if(!i || !j) return;

    if(numsn[i] == numsm[j] && dp[i - 1][j - 1] + 1 == dp[i][j]){
        dfs(i - 1, j - 1);
        fout << numsn[i] << " ";
    }
    else if(dp[i][j] == dp[i - 1][j]) dfs(i - 1, j);
    else dfs(i, j - 1);

}

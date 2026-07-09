#include <bits/stdc++.h>
using namespace std;
const int MAXN = (1 << 10) + 3;
int a[MAXN], b[MAXN], dp[MAXN][MAXN], maxim ;
vector <int> ans;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int main(){
    int n, m; fin >> n >> m;
    ans.push_back({0});
    for(int i = 1; i <= n; ++i) fin >> a[i];
    for(int i = 1; i <= m; ++i) fin >> b[i];
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= m; ++j){
            if(i == 0 or j == 0) dp[i][j] = 0;
            dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
            dp[i][j + 1] = max(dp[i][j], dp[i][j + 1]);
            dp[i + 1][j + 1] = dp[i][j] + (a[i + 1] == b[j + 1]);
            if(i == 0 or j == 0 or dp[i][j] == dp[i][j - 1]) continue;
            if(ans.back() != j) ans.push_back(j);
        }
    }
    fout << dp[n][m] << '\n';
    for(auto x : ans)
        if(x != 0) fout << b[x] << " ";
    return 0;
}

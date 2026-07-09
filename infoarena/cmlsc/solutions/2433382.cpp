#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1030;

int sec1[MAXN], sec2[MAXN];
int dp[MAXN][MAXN];
vector<int> ans;

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    int n, m;
    fin >> n >> m;
    for(int i = 1; i <= n; ++i) fin >> sec1[i];
    for(int i = 1; i <= m; ++i) fin >> sec2[i];
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(sec1[i] == sec2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    fout << dp[n][m] << "\n";
    int l = n, c = m;
    while(l && c){
        if(sec1[l] == sec2[c]){
            ans.push_back(sec1[l]);
            l--;
            c--;
            continue;
        }
        if(dp[l][c] == dp[l - 1][c]){
            l--;
            continue;
        }
        c--;
    }
    for(int i = ans.size() - 1; i >= 0; --i)
        fout << ans[i] << " ";
    return 0;
}

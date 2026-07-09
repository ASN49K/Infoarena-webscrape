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
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int p1 = n, p2 = m;
    while(p1 && p2){
        if(dp[p1][p2] == dp[p1 - 1][p2 - 1] + 1){
            ans.push_back(sec1[p1]);
            p1--;
            p2--;
        }
        else if(dp[p1][p2] == dp[p1 - 1][p2]) p1--;
        else p2--;
    }
    reverse(ans.begin(), ans.end());
    fout << dp[n][m] << "\n";
    for(auto x:ans)
        fout << x << " ";
    return 0;
}

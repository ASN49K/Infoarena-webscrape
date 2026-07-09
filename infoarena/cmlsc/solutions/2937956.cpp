#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int maxn = 1024;
int n, m;
int a[maxn + 2], b[maxn + 2];
int dp[maxn + 2][maxn + 2];
void solve(){
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j){
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
}
void drum(int i, int j){
    if(i == 0 || j == 0)
        return ;
    if(a[i] == b[j]){
        drum(i - 1, j - 1);
        fout << a[i] << " ";
    }
    else if(dp[i][j - 1] > dp[i - 1][j])
        drum(i, j -  1);
        else drum(i - 1, j);
}
int main(){
    fin >> n >> m;
    for(int i = 1; i <= n; ++i) fin >> a[i];
    for(int i = 1; i <= m; ++i) fin >> b[i];
    solve();
    fout << dp[n][m] << "\n";
    drum(n, m);
    return 0;
}
/*

*/
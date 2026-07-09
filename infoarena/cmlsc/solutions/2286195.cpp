#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 200005

int a[1030], b[1030], prec[1030];
int dp[1025][1025];
vector <int> ans;
int n, m, last;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
signed main(){
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> a[i];
    for (int i = 1; i <= m; i++)
        fin >> b[i];
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++){
        if (b[j] == a[i]){
            dp[i][j] = dp[i-1][j-1] + 1;
            prec[j] = last;
            last = j;
        }
        else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
    fout << dp[n][m] << "\n";
    while (last){
        ans.push_back(b[last]);
        last = prec[last];
    }
    for (int i = ans.size() - 1; i >= 0; i--)
        fout << ans[i] << ' ';
}

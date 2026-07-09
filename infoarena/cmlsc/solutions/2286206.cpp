#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 200005
#define cin fin
#define cout fout


int a[1030], b[1030];
int dp[1025][1025];
vector <int> ans;
int n, m, last;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

signed main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++){
        if (b[j] == a[i]){
            dp[i][j] = dp[i-1][j-1] + 1;
            ans.push_back(a[i]);
        }
        else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
    cout << dp[n][m] << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
}

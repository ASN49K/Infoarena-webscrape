#include <bits/stdc++.h>
using namespace std;

int n, m, a[1030], b[1030], c[1030], k, dp[1030][1030];
vector <int> v;

int main(){
    ifstream cin ("cmlsc.in");
    ofstream cout ("cmlsc.out");
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=m; i++) cin >> b[i];
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int i = n, j = m;
    while (i && j){
        if (a[i] == b[j]) c[++k] = a[i], i--, j--;
        else if (dp[i][j-1] > dp[i-1][j]) j--;
        else i--;
    }
    cout << dp[n][m] << "\n";
    for (i = k; i; i--) cout << c[i] << " ";
    return 0;
}

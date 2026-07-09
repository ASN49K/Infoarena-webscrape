#include <bits/stdc++.h>
using namespace std;

#define N 1030
int n, m, a[N], b[N], dp[N][N], sol[N], k;

int main(){
    ifstream cin ("cmlsc.in");
    ofstream cout ("cmlsc.out");
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> b[i];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    cout << dp[n][m] << '\n';
    int i = n, j = m;
    while (i && j){
        if (dp[i][j] == dp[i-1][j]) i--;
        else if (dp[i][j] == dp[i][j-1]) j--;
        else sol[++k] = a[i], i--, j--;
    }
    for (int i=k; i; i--) cout << sol[i] << ' ';
    return 0;
}

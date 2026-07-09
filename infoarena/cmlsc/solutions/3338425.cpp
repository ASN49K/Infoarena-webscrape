#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

#define cin fin
#define cout fout
#define ll long long

int a[1501], b[1501];
int n, m;
int dp[1101][1101];

int main() {

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if (a[i]==b[j]) {
                dp[i][j] = dp[i-1][j-1]+1;
            } else {
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    cout << dp[n][m] << "\n";
    string ans = "";
    int i = n, j=m;
    while(i > 0 && j > 0) {
        if (a[i]==b[j]) {
            ans = to_string(a[i]) + " "+ ans;
            i--;
            j--;
        } else if (dp[i-1][j]>dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    cout << ans;
    return 0;
}

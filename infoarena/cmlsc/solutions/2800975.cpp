/* [A][M][C][B][N] / [K][R][I][P][6][8] */
#include <bits/stdc++.h>
using namespace std;
const char sp = ' ', nl = '\n';
const int MOD = 10007;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int dp[1025][1025]{0}, a[1025]{0}, b[1025]{0}, n, m;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];
    for (int i = 1; i <= m; ++i)
        fin >> b[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    fout << dp[n][m] << nl;
    stack<int> st;
    int i = n, j = m;
    while (i && j) {
        if (a[i] == b[j])
            st.push(a[i]), --i, --j;
        else {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }
    while (!st.empty())
        fout << st.top() << sp, st.pop();
}
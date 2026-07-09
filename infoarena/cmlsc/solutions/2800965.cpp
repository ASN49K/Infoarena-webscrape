/* [A][M][C][B][N] / [K][R][I][P][6][8] */
#include <bits/stdc++.h>
using namespace std;
const char sp = ' ', nl = '\n';
const int MOD = 10007;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int dp[1024][1024], a[1024], b[1024];
int n, m;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    fin >> n >> m;
    for (int i = 0; i < n; ++i)
        fin >> a[i];
    for (int i = 0; i < m; ++i)
        fin >> b[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i] == b[j])
                dp[i][j] = ((!i | !j) ? 0 : dp[i - 1][j - 1]) + 1;
            else
                dp[i][j] = max((!i ? 0 : dp[i - 1][j]), (!j ? 0 : dp[i][j - 1]));
    fout << dp[n - 1][m - 1] << nl;
    stack<int> st;
    int i = n - 1, j = m - 1;
    while (i >= 0 && j >= 0)
        if (a[i] == b[j])
            st.push(a[i]), --i, --j;
        else
            (dp[i - 1][j] > dp[i][j - 1] ? i : j)--;
    while (!st.empty())
        fout << st.top() << sp, st.pop();
}
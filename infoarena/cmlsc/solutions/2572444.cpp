#include <bits/stdc++.h>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

void usain_bolt()
{
    ios::sync_with_stdio(false);
    fin.tie(0);
}

const int N = 1025;

int a[N], b[N], dp[N][N], ans[N];

int main()
{
    usain_bolt();

    int n, m;

    fin >> n >> m;
    for(int i = 1; i <= n; ++i) fin >> a[i];
    for(int i = 1; i <= m; ++i) fin >> b[i];
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    fout << dp[n][m] << "\n";
    int i = n, j = m;
    while(i >= 1 && j >= 1) {
        if(a[i] == b[j]) ans[++ans[0]] = a[i], --i, --j;
        else if(dp[i - 1][j] >= dp[i][j - 1]) --i;
        else --j;
    }
    for(int i = ans[0]; i >= 1; --i) fout << ans[i] << " ";
    return 0;
}

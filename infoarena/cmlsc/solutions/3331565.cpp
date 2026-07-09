#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[1100][1100];

int main() {
    int n, m, a[1100], b[1100];
    fin >> n >> m;
    for (int i = 0; i < n; i++) fin >> a[i];
    for (int i = 0; i < m; i++) fin >> b[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    string afis;
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            afis.push_back(a[i - 1] + '0');
            afis.push_back(' ');
            i--;
            j--;
        }
        else if (dp[i - 1][j] < dp[i][j - 1])
            j--;
        else
            i--;
    }
    reverse(afis.begin(), afis.end() - 1);
    fout << dp[n][m] << '\n' << afis;
}

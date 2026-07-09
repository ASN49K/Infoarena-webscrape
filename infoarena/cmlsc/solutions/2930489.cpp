#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int n, m;
    fin >> n >> m;

    vector<int> a(n), b(m);
    for (int& x : a)
        fin >> x;

    for (int &x : b)
        fin >> x;

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i] == b[j])
                dp[i][j] = i && j ? dp[i - 1][j - 1] + 1 : 1;
            else
                dp[i][j] = max(i ? dp[i - 1][j] : 0, j ? dp[i][j - 1] : 0);

    vector<int> ans;
    for (int i = n - 1, j = m - 1; i >= 0 && j >= 0;)
        if (a[i] == b[j]) {
            ans.push_back(a[i]);
            --i;
            --j;
        } else if ((i ? dp[i - 1][j] : 0) < (j ? dp[i][j - 1] : 0))
            --j;
        else
            --i;

    reverse(ans.begin(), ans.end());

    fout << ans.size() << '\n';
    for (int x : ans)
        fout << x << ' ';
    fout << '\n';
}
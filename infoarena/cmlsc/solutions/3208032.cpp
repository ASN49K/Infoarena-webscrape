#include <bits/stdc++.h>

int lcs_len(int n, std::vector<int> &v, int m, std::vector<int> &w,
            std::vector<std::vector<int>> &dp)
{
    // if (n == 0 || m == 0)
    //     dp[n][m] = 1;
    // else if (v[n] == w[m])
    //     dp[n][m] = 1 + lcs_len(n - 1, v, m - 1, w, dp);
    // else
    //     dp[n][m] = std::max(lcs_len(n - 1, v, m, w, dp), lcs_len(n, v, m - 1, w, dp));

    // return dp[n][m];

    if (n == -1 || m == -1)
        return 0;
    
    int &len = dp[n][m];

    if (len != 0)
        return len;

    if (v[n] == w[m])
        len = 1 + lcs_len(n - 1, v, m - 1, w, dp);
    else
        len = std::max(lcs_len(n - 1, v, m, w, dp), lcs_len(n, v, m - 1, w, dp));

    return len;
}

std::vector<int> lcs(std::vector<int> v, std::vector<std::vector<int>> &dp)
{
    int n, m;
    int len;
    std::vector<int> seq;

    n = dp.size() - 1;
    m = dp[0].size() - 1;
    len = dp[n][m];

    while (n != 0 && m != 0) {
        if (m > 1 && dp[n][m - 1] == len) {
            --m;
        } else if (n > 1 && dp[n - 1][m] == len) {
            --n;
        } else {
            seq.insert(seq.begin(), v[n]);
            --n;
            --m;
            --len;
        }
    }

    return seq;
}

int main()
{
    std::ifstream fin("cmlsc.in");
    std::ofstream fout("cmlsc.out");

    int n, m;
    std::vector<int> v;
    std::vector<int> w;
    std::vector<std::vector<int>> dp;

    fin >> n >> m;
    v.resize(n, 0);
    w.resize(m, 0);
    dp.resize(n, std::vector<int>(m, 0));

    for (int i = 0; i < n; ++i)
        fin >> v[i];

    for (int i = 0; i < m; ++i)
        fin >> w[i];

    fout << lcs_len(n - 1, v, m - 1, w, dp) << '\n';

    for (auto &nr : lcs(v, dp))
        fout << nr << ' ';
    fout << '\n';

    // for (int i = 0; i < v.size(); ++i) {
    //     for (int j = 0; j < w.size(); ++j)
    //         std::cout << dp[i][j] << ' ';

    //     std::cout << '\n';
    // }

    fin.close();
    fout.close();

    return 0;
}

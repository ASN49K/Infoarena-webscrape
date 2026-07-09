#include <bits/stdc++.h>

int main()
{
    std::ifstream fin("cmlsc.in");
    std::ofstream fout("cmlsc.out");

    int n, m;
    std::vector<int> v;
    std::vector<int> w;
    std::vector<int> seq;
    std::vector<std::vector<int>> dp;

    fin >> n >> m;
    v.resize(n, 0);
    w.resize(m, 0);
    dp.resize(n, std::vector<int>(m, 0));

    for (int i = 0; i < n; ++i)
        fin >> v[i];

    for (int i = 0; i < m; ++i)
        fin >> w[i];

    for (int i = 0; i < n; ++i) {
        if(w[0] == v[i]) {
            dp[i][0] = 1;
            for (int j = i + 1; j < n; ++j)
                dp[j][0] = 1;

            break;
        }
    }

    for (int i = 0; i < m; ++i) {
        if(v[0] == w[i]) {
            dp[0][i] = 1;
            for (int j = i + 1; j < m; ++j)
                dp[0][j] = 1;

            break;
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (v[i] == w[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // for (int i = 0; i < v.size(); ++i) {
    //     for (int j = 0; j < w.size(); ++j)
    //         std::cout << dp[i][j] << ' ';

    //     std::cout << '\n';
    // }

    fout << dp[n - 1][m - 1] << '\n';

    // for (int i = n - 1, j = m - 1; i != 0 && j != 0;) {
    //     if (i > 0 && dp[i - 1][j] == dp[i][j]) {
    //         --i;
    //     } else if (j > 0 && dp[i][j - 1] == dp[i][j]) {
    //         --j;
    //     } else {
    //         seq.insert(seq.begin(), v[i]);
    //         --i;
    //         --j;
    //     }
    // }

    for (int i = n - 1, j = m - 1; i;) {
        if (v[i] == w[j])
            seq.insert(seq.begin(), v[i]), --i, --j;
        else if (dp[i-1][j] < dp[i][j-1])
            --j;
        else
            --i;
    }

    if (seq.size()) {
        for (auto &elem : seq)
            fout << elem <<  ' ';
        fout << '\n';
    }

    fin.close();
    fout.close();

    return 0;
}

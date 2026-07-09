#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#define NMAX 1025

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int dp[NMAX][NMAX];
int v[NMAX], s[NMAX];

int main() {
    int n, m;
    in >> n >> m;
    for (int i = 1; i <= n; ++i)
        in >> v[i];
    for (int i = 1; i <= m; ++i)
        in >> s[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int a = dp[i][j - 1];
            int b = dp[i - 1][j];
            int c = dp[i - 1][j - 1] + 1;
            dp[i][j] = max(a, b);
            if (v[i] == s[j])
                dp[i][j] = max(dp[i][j], c);
        }
    }

    out << dp[n][m] << '\n';
    /*for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            cout << dp[i][j] << " ";
        cout << '\n';
    }*/

    for (int i = 0; i < n; ++i) {
        if (dp[i][m] != dp[i + 1][m])
            out << v[i + 1] << " ";
    }

    out << '\n';
    return 0;
}
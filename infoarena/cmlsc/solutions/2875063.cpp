#include <bits/stdc++.h>
#define MAX_N 1024

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

void citire(int &n, int &m, int a[], int b[]) {
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> a[i];
    for (int i = 1; i <= m; i++)
        fin >> b[i];
}

void tabel(int n, int m, int a[], int b[], int dp[][MAX_N + 1]) {
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
}

void rezolvare(int n, int m, int a[], int b[]) {
    vector<int> sir;
    int dp[MAX_N + 1][MAX_N + 1];
    tabel(n, m, a, b, dp);
    for (int i = n, j = m; i && j;) {
        if (a[i] == b[j])
            sir.push_back(a[i]), i--, j--;
        else if (dp[i - 1][j] < dp[i][j - 1])
            j--;
        else
            i--;
    }

    fout << dp[n][m] << '\n';
    for (int i = sir.size() - 1; i >= 0; i--)
        fout << sir[i] << ' ';
}

int main() {
    int n, m, a[MAX_N + 1], b[MAX_N + 1];
    citire(n, m, a, b);
    rezolvare(n, m, a, b);
    return 0;
}

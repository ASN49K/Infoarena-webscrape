#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, v1[1030], v2[1030], dp[1030][1030], ans[1030], ind;

int main() {
    fin >> n >> m;
    for(int i = 1; i <= n; i++) {
        fin >> v1[i];
    }
    for(int i = 1; i <= m; i++) {
        fin >> v2[i];
    }
    fin.close();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(v1[i] == v2[j]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    while(n > 0) {
        if(v1[n] == v2[m]) {
            ans[++ind] = v1[n--];
            m--;
        } else {
            if(dp[n - 1][m] < dp[n][m - 1]) {
                m--;
            } else {
                n--;
            }
        }
    }
    fout << ind << "\n";
    for(int i = ind; i > 0; i--) {
        fout << ans[i] << " ";
    }
    return 0;
}
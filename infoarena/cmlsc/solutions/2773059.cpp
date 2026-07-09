#include <bits/stdc++.h>
#define NMAX 1025

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int dp[NMAX][NMAX], v1[NMAX], v2[NMAX], ans[NMAX*NMAX+1];
int main() {
    int n, m;
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> v1[i];
    for(int j = 1; j <= m; j++)
        fin >> v2[j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            if(v1[i] == v2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j -1 ]);
        }
    fout << dp[n][m] << '\n';
    int i = n, j = m, k = 0;
    while(i >= 1 && j >= 1) {
        if(v1[i] == v2[j]) {
            k++;
            ans[k] = v1[i];
            i--;
            j--;
        }
        else {
            if(dp[i - 1][j] >= dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    for(int i = k; i >= 1; i--)
        fout << ans[i] << ' ';
}

#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, a[1024], b[1024];
    fin>>m>>n;
    for(int i = 1; i <= m; i++) {
        fin>>a[i];
    }
    for(int j = 1; j <= n; j++) {
        fin>>b[j];
    }
    int dp[1024][1024];
    // cel mai lung subsir comun
    // dp[i][j] - cu primele i elemente din a si primele
    // j din b
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i] == b[j]) {
                dp[i][j] = 1 + dp[i-1][j -1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j -1]);
            }
        }
    }
    fout<<dp[n][m];
    int drum[1024];
    int length = 0;
    int i = m, j = n;
    while(i > 0 && j > 0) {
        if(a[i] == b[i]) {
            drum[length++] = a[i];
            i--;
            j--;
        } else if(dp[i-1][j] < dp[i][j-1]) {
            j--;
        } else {
            i--;
        }
    }
    for(int i = length; i >= 1; i--) {
        fout<<drum[i]<<" ";
    }
    return 0;
}
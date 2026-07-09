#include <bits/stdc++.h>

using namespace std;

int dp[1024][1024];
int v[1024], v1[1024];

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main() {
    int n, k; fin >> n >> k;
    for(int i = 1; i <= n; i++) {
        fin >> v[i];
    }
    for(int i = 1; i <= k; i++) {
        fin >> v1[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(v[i] == v1[j])  {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    /*for(int i = 1; i <= n; i++, cout << "\n") {
        for(int j = 1; j <= k; j++) {
            cout << dp[i][j] << "  ";
        }
    }*/
    fout << dp[n][k];
    return 0;
}

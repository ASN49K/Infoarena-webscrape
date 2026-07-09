#include<bits/stdc++.h>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int main() {
    int N, M;
    in >> N >> M;
    int a[N + 1], b[M + 1];
    for(int i = 1; i <= N; ++i) {
        in >> a[i];
    }
    for(int i = 1; i <= M; ++i) {
        in >> b[i];
    }
    int dp[N + 1][M + 1];
    pair<int,int> deUnde[N + 1][M + 1];
    for(int i = 0; i <= N; ++i) {
        for(int j = 0; j <= M; ++j) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }
            if(dp[i - 1][j] > dp[i][j - 1]) {
                deUnde[i][j] = make_pair(i - 1, j);
                dp[i][j] = dp[i - 1][j];
            } else {
                deUnde[i][j] = make_pair(i, j - 1);
                dp[i][j] = dp[i][j - 1];
            }
            if(a[i] == b[j]) {
                if(dp[i - 1][j - 1] + 1 > dp[i][j]) {
                    deUnde[i][j] = make_pair(i - 1, j - 1);
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
            }
        }
    }
    out << dp[N][M] << '\n';
    int sol[N + 1], L = 0;
    while(dp[N][M] > 0) {
        int pN = deUnde[N][M].first, pM = deUnde[N][M].second;
        if(pN == N - 1 && pM == M - 1) {
            sol[L++] = a[N];
        }
        N = pN, M = pM;
    }
    for(int i = L - 1; i >= 0; --i) out << sol[i] << ' ';
}
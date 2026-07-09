#include <bits/stdc++.h>
 
using namespace std;
 
inline void Open(const string Name) {
    #ifndef ONLINE_JUDGE
        (void)!freopen((Name + ".in").c_str(), "r", stdin);
        (void)!freopen((Name + ".out").c_str(), "w", stdout);
    #endif
}
 
const long long INF = 1e18;
 
long long dp[501][501];
int v[501];
int N;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    Open("a");
 
    cin >> N;
    for(int i = 0;i <= N;i++)
        cin >> v[i];
 
    for(int pas = 2;pas <= N;pas++)
        for(int i = 1;i <= N - pas + 1;i++) {
            int j = i + pas - 1;
            dp[i][j] = INF;
            for(int k = i;k < j;k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + 1LL * v[i - 1] *  v[k] * v[j]);
        }

    for(int i = 0;i <= N;i++, cout << "\n")
        for(int j = 0;j <= N;j++)
            cout << dp[i][j] <<  " ";
 
    return 0;
 
}
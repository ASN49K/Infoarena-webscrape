#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

std::ifstream f("cmlsc.in");
std::ofstream g("cmlsc.out");

int n, m, dp[1025][1025];
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    // f.tie(NULL);
    // g.tie(NULL);
    
    f >> n >> m;
    std::vector<int> a(n + 5), b(m + 5);
    for(int i = 1; i <= n; ++i)
        f >> a[i];
    for(int j = 1; j <= m; ++j)
        f >> b[j];
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
            dp[i][j] = std::max({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1] + (b[i] == a[j])});
    g << dp[n][m] << '\n';
    for(int i = 1; i <= dp[n][m]; ++i)
        g << 1 << ' ';
    return 0;
}
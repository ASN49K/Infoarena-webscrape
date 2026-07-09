#include <bits/stdc++.h>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

const int N = 1025;

int n, m;
uint16_t a[N], b[N], dp[N][N];
stack<uint16_t> rez;

int main()
{
    f >> n >> m;
    for (int i = 1; i <= n; i++) 
        f >> a[i];
    for (int j = 1; j <= m; j++)
        f >> b[j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    g << dp[n][m] << '\n';
    int i = n, j = m;
    while (dp[i][j]){
        if (dp[i][j] == dp[i - 1][j - 1] + 1){
            rez.push(a[i]);
            i--; j--;
        }
        else 
            dp[i][j - 1] > dp[i - 1][j] ? j-- : i--;
    }
    while (!rez.empty()){
        g << rez.top() << ' '; rez.pop();
    }
    
    
    return 0;
}
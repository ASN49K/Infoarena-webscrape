#include <bits/stdc++.h>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int v[1025], w[1025], dp[1025][1025], ans[1025];

int main()
{
    int n, m;
    in >> n >> m;
    for(int i = 1; i <= n; i++)
        in >> v[i];
    for(int i = 1; i <= m; i++)
        in >> w[i];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(v[i] == w[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    out << dp[n][m] << '\n';

    int nans = 0;
    for(int i = n, j = m; i >= 1 && j >= 1;){
        if(v[i] == w[j]){
            ans[++nans] = v[i];
            i--;
            j--;
        }
        else if(dp[i][j] == dp[i-1][j]){
            i--;
        }
        else if(dp[i][j] == dp[i][j-1]){
            j--;
        }
    }
    for(int i = nans; i >= 1; i--){
        out << ans[i] << " ";
    }
    return 0;
}

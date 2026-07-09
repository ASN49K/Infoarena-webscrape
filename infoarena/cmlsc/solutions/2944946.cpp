#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, a[1030], b[1030], dp[1030][1030], sol[1030];
int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++) fin >> a[i];
    for(int i = 1; i <= m; i++) fin >> b[i];
    for(int i = 1; i <= n; i++)
        dp[i][1] = (a[i] == b[1]);
    for(int i = 1; i <= m; i++)
        dp[1][i] = (a[1] == b[i]);
    for(int i = 2; i <= n; i++)
        for(int j = 2; j <= m; j++)
            if(a[i] == b[j]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    fout << dp[n][m] << '\n';
    int ic = n, jc = m;
    while(ic > 0 && jc > 0){
        if(a[ic] == b[jc])
            sol[++sol[0]] = a[ic];
        if(dp[ic - 1][jc] > dp[ic][jc - 1]) ic--;
        else jc--;
    }
    for(int i = sol[0]; i > 0; i--) fout << sol[i] << ' ';
    /**

    **/
}

#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[1025][1025];
int a[1025] ,b[1025];
vector <int> an;
int main() {
    int m, n;
    fin >> m >> n;
    for(int i = 1;i <= m; ++i)
        fin >> a[i];
    for(int i = 1;i <= n; ++i)
        fin >> b[i];
    for(int i = 1;i <= m; ++i)
        for(int j = 1;j <= n; ++j)
            if(a[i] == b[j]) {
                dp[i][j] = 1+ dp[i-1][j-1];
            }
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) ;

    cout << dp[m][n] <<"\n";
    int ans = 0;
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            if(dp[i][j]>ans) {
                cout << a[i] <<" ";
                ans=dp[i][j];
            }

    return 0;
}

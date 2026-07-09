#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[1025][1025];
int a[1025] ,b[1025];
set <int> ans;

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
                ans.insert(a[i]);
            }
            else
                dp[i][j] = max(dp[i][j - 1], dp[i][j]) ;
    fout << ans.size() <<"\n";
    for(auto x : ans){
        fout << x << " ";
    }
    return 0;
}

#include <iostream>
#include <fstream>
#include <vector>
//#include <bits/stdc++.h>
#define in fin
#define out fout

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; in >> n >> m;
    int a[n + 1], b[m + 1];
    for(int i = 1; i <= n; i++) in >> a[i];
    for(int i = 1; i <= m; i++) in >> b[i];

    int dp[n + 1][m + 1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++) dp[i][j] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i] == b[j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            dp[i][j] = max(dp[i][j], dp[i][j - 1]);
        }
    }

    out << dp[n][m] << '\n';

    vector<int> sol;
    int x = n, y = m;
    while(x != 0 && y != 0){
        if(a[x] == b[y] && dp[x][y] == dp[x - 1][y - 1] + 1){
            sol.push_back(a[x]);
            x--, y--;
            continue;
        }

        if(dp[x][y] == dp[x - 1][y]) x--;
        else y--;
    }

    for(int i = sol.size() - 1; i >= 0; i--) out << sol[i] << " ";
    out << '\n';

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int main(){
    int n, m;
    in >> n >> m;
    vector<int> v1(n+1), v2(m+1);
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    for(int i = 0; i < n; i++)
        in >> v1[i];
    for(int j = 0; j < m; j++)
        in >> v2[j];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){

            if(v1[i - 1] == v2[j - 1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    out << dp[n][m] << endl;

    vector<int> ans;
    int i = n, j = m;

    while(i > 0 && j > 0) {
        if(v1[i-1] == v2[j-1]) {
            ans.push_back(v1[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }

    reverse(ans.begin(), ans.end());
    for(int x : ans)
        out << x << " ";
}
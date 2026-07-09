#include <bits/stdc++.h>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int n, m;
void fr(vector<vector<int>> &dp, vector<int> &v, vector<int> &x, int i, int j);
int main(){
    fin >> n >> m;
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    vector<int> v(n+1), x(m+1);
    for (int i = 1; i <= n; i++)
        fin >> v[i];
    for (int i = 1; i <= m; i++)
        fin >> x[i];
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (v[i] == x[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    fout << dp[n][m] << '\n';
    fr(dp, v, x, n, m);
    return 0;
}
void fr(vector<vector<int>> &dp, vector<int> &v, vector<int> &x, int i, int j){
    if (dp[i][j] == 0)
        return;
    if (dp[i][j] > max(dp[i][j-1], dp[i-1][j])){
        fr(dp, v, x, i-1, j-1);
        fout << v[i] << ' ';
    }
    else if (dp[i-1][j] > dp[i][j-1]) /// dp[i][j] == max(dp[i][j-1], dp[i-1][j]))
        fr(dp, v, x, i-1, j);
    else
        fr(dp, v, x, i, j-1);
    
}
/*
stack<int> s;
    int i = n, j = m;
    while (dp[i][j] > 0){
        if (dp[i][j] > max(dp[i][j-1], dp[i-1][j])){
            s.push(v[i]);
            i--;  j--;
        }
        else if (dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
        
    }
    fout << dp[n][m] << '\n';
    while (!s.empty()){
        fout << s.top() << ' ';
        s.pop();
    }
*/
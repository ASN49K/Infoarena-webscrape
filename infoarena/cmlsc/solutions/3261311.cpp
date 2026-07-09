#include<bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int ans[1025];
int main() {
    int n, m, cnt = 0;
    fin >> n >> m;
    vector<int> a(n + 1);
    vector<int> b(m + 1);
    for(int i = 1; i <= n; i++){
        fin >> a[i];
    }
    for(int i = 1; i <= m; i++){
        fin >> b[i];
    }
    int dp[n + 1][m + 1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int i = n, j = m;
    while(i != 0 && j != 0){
        if(a[i] == b[j]){
            ans[++cnt] = a[i];
            i--;
            j--;
        }
        else if(dp[i - 1][j] < dp[i][j - 1]){
            j--;
        }
        else{
            i--;
        }
    }
    fout << cnt << '\n';
    for(int i = cnt; i >= 1; i--){
        fout << ans[i] << " ";
    }
    return 0;
}

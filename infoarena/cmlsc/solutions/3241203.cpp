#include "bits/stdc++.h"
const int DIM = 1024;
int dp[DIM + 5][DIM + 5], a[DIM + 5], b[DIM + 5], n, m;
std :: vector  < int > res;
inline static void Solve(){
            std :: cin >> n >> m;
            for(int i = 1; i <= n; i++){
                     std :: cin >> a[i];
            }
            for(int j = 1; j <= m; j++){
                      std :: cin >> b[j];
            }
            for(int i = 1; i <= n; i++){
                     for(int j = 1; j <= m; j++){
                              if(a[i - 1] == b[j - 1])
                                    dp[i][j] = dp[i - 1][j - 1] + 1;
                               else
                                     dp[i][j] = std :: max(dp[i - 1][j] , dp[i][j - 1]);
                     }
            }
            std :: cout << dp[n][m] << '\n';
            int i = n, j = m;
            while(i and j){
                    if(a[i] == b[j]){
                        res.push_back(a[i]);
                        i--;
                        j--;
                    }
                    else if(dp[i-1][j] > dp[i][j-1]){
                           i--;
                    }else{
                           j --;
                    }
            }
            std :: reverse(res.begin(), res.end());
            for(auto i : res){
                  std :: cout << i << ' ';
            }
}
signed main(){
        freopen("cmlsc.in","r",stdin);
        freopen("cmlsc.out","w",stdout);
        std :: ios_base :: sync_with_stdio(false);
        std :: cin.tie(0);
        std :: cout.tie(0);
        Solve();
        return 0;
}

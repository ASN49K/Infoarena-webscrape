#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

const int NMax = 1031;

int n,m,mx,si,sj;
int a[NMax],b[NMax],dp[NMax][NMax];


int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; ++i)
        f >> a[i];
    for(int j = 1; j <= m; ++j)
        f >> b[j];
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(a[i] == b[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int i = n, j = m;
    g << dp[n][m] << '\n';
    vector<int> ans;

    while(true){
        if(i <= 0 || j <= 0)
            break;
        if(dp[i][j] == dp[i - 1][j]){
            i--;
        }else{
            if(dp[i][j] == dp[i][j - 1]){
                j--;
            }else{
                if(dp[i][j] == dp[i - 1][j - 1] + 1){
                    ans.push_back(a[i]);
                    i--;
                    j--;
                }
            }
        }
    }
    for(int i = ans.size() - 1; i >= 0; --i){
        g << ans[i] << ' ';
    }
    return 0;
}

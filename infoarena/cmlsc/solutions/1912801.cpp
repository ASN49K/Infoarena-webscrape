#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

const int NMax = 1031;

int n,m,mx;
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
            mx = max(dp[i][j],mx);
        }
    }
    for(int i = 0; i <= n + 1; ++i)
        dp[i][0] = -2;
    for(int i = 0; i <= m + 1; ++i)
        dp[0][i] = -2;

    g << mx << '\n';
    vector<int> ans;
    int i = n, j = m;
    while(true){
        if(i == 1 && j == 1)
            break;
        if(dp[i][j] == dp[i - 1][j - 1] + 1){
            ans.push_back(a[i]);
            i --;
            j--;
        }else{
            if(dp[i][j] == dp[i - 1][j]){
                i--;
            }else
                if(dp[i][j] == dp[i][j - 1]){
                    j--;
                }
        }
    }
    for(int i = ans.size() - 1; i >= 0; --i){
        g << ans[i] << ' ';
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

const int NMax = 1030;

int N,M;
int a[NMax],b[NMax],dp[NMax][NMax];

int main()
{
    f >> N >> M;
    for(int i = 1; i <= N; ++i)
        f >> a[i];
    for(int i = 1; i <= M; ++i)
        f >> b[i];
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            if(a[i] == b[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    g << dp[N][M] << '\n';

    int i = N, j = M;

    int k = 0;

    vector<int> ans;

    while(true){

        if(i <= 0 || j <= 0)
            break;
        if(dp[i][j] == dp[i][j - 1]){
            j--;
        }else{
            if(dp[i][j] == dp[i - 1][j]){
                i--;
            }else
            if(dp[i][j] == dp[i - 1][j - 1] + 1){
                ans.push_back(a[i]);
                i--;
                j--;
            }
        }
    }
    for(int i = ans.size() - 1; i >= 0; --i){
        g << ans[i] << ' ';
    }
    return 0;
}

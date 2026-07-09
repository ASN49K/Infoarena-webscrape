#include <bits/stdc++.h>

using namespace std;

int n , m;

int A[1025] , B[1025];

int dp[1025][1025];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("cmlsc.in" , "r" , stdin);
    freopen("cmlsc.out" , "w" , stdout);
    cin >> n >> m;
    for(int i = 1;i <= n; ++i)
        cin >> A[i];
    for(int i = 1;i <= m; ++i)
        cin >> B[i];
    for(int i = 1;i <= n; ++i)
        for(int j = 1;j <= m; ++j)
            if(A[i] == B[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
    vector <int> ans;
    int i = n , j = m;
    while(i > 0){
        if(A[i] == B[j]){
            ans.push_back(A[i]);
            --i,--j;
        }
        else if(dp[i][j] == dp[i - 1][j])
                --i;
            else --j;
    }
    cout << dp[n][m] << "\n";
    for(i = ans.size() - 1;i >= 0; --i)
        cout << ans[i] << " ";
}

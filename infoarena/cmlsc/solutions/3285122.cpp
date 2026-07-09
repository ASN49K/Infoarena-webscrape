#include<bits/stdc++.h>
using namespace std;

const int NMAX = 1030;
int n, m, a[NMAX], b[NMAX], dp[NMAX][NMAX];
vector<int> ans;

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= m; i++)
        cin >> b[i];
        
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i] != b[j])
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            if(a[i] == b[j])
            {
                dp[i][j] = dp[i -1][j - 1] + 1;
            }
        }
    }
    
    cout << dp[n][m] << "\n";
    int i = n, j = m;
    while(i >= 1 && j >= 1)
    {
        int max1;
        max1 = max(dp[i - 1][j], max(dp[i - 1][j - 1], dp[i][j - 1]));
        if(dp[i][j] != dp[i - 1][j] && dp[i][j] != dp[i - 1][j - 1] && dp[i][j] != dp[i][j - 1])
            ans.push_back(a[i]);
        if(dp[i - 1][j] == max1)
            i--;
        else if(dp[i][j - 1] == max1)
            j--;
        else
        {
            i--;
            j--;
        }
    }
    
    for(int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
}
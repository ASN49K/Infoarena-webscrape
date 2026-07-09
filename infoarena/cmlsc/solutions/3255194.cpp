#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n, m;
vector<int> a, b, ans;
vector<vector<int>> dp;
int main()
{
    cin >> n >> m;
    a.resize(n+1);
    b.resize(m+1);
    dp.resize(n+1, vector<int>(m+1));
    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int j=1; j<=m; j++)
        cin >> b[j];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    cout << dp[n][m] << '\n';
    for(int i=n, j=m; dp[i][j];)
        if(a[i] == b[j])
        {
            ans.push_back(a[i]);
            i--;
            j--;
        }
        else
            if(dp[i][j] == dp[i-1][j])
                i--;
            else
                j--;
   // cout << ans.size() << '\n';
    reverse(ans.begin(), ans.end());
    for(auto i:ans)
        cout << i << " ";

    return 0;
}

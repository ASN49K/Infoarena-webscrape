#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int main()
{
    int na, nb;
    cin >> na >> nb;
    vector<int> a(na + 1), b(nb + 1);
    for(int i = 1; i <= na; ++i) cin >> a[i];
    for(int i = 1; i <= nb; ++i) cin >> b[i];
    vector<vector<int> > dp(na + 1);
    for(int i = 0; i <= na; ++i)
        dp[i].resize(nb + 1, 0);
    for(int i = 1; i <= na; ++i)
        for(int j = 1; j <= nb; ++j)
            if(a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    cout << dp[na][nb] << '\n';
    vector<int> sol;
    while(dp[na][nb] > 0) {
        if(a[na] == b[nb]) {
            sol.push_back(a[na]);
            --na;
            --nb;
        } else if(dp[na][nb] == dp[na - 1][nb]) {
            --na;
        } else {
            --nb;
        }
    }
    for(int i = sol.size() - 1; i >= 0; --i)
        cout << sol[i] << ' ';
    return 0;
}

#include <fstream>
#include <cmath>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

const int MAX_N = 1024;

int n, m;

int v1[MAX_N + 1], v2[MAX_N + 1];
int dp[MAX_N + 1][MAX_N + 1];
int ans[MAX_N + 1], idx_ans;
int idx1, idx2;

int main()
{

    cin >> n >> m;

    idx1 = n, idx2 = m, idx_ans;

    for(int i = 1; i <= n; i++)
        cin >> v1[i];

    for(int i = 1; i <= m; i++)
        cin >> v2[i];


    for(int idx1 = 1; idx1 <= n; idx1++)
    {
        for(int idx2 = 1; idx2 <= m; idx2++)
        {
            if(v1[idx1] == v2[idx2])
                dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
            else
                dp[idx1][idx2] = max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
            }
    }

    idx_ans = dp[n][m];

    while(idx1 > 0 && idx2 > 0)
    {
        if(v1[idx1] == v2[idx2])
        {
            ans[idx_ans] = v1[idx1];
            idx_ans--;
            idx1--;
            idx2--;
        }
        else if(dp[idx1 - 1][idx2] > dp[idx1][idx2 - 1]) idx1--;
        else idx2--;
    }

    cout << dp[n][m] << endl;

    for(int i = 1; i <= dp[n][m]; i++)
        cout << ans[i] << " ";

    return 0;
}

#include <fstream>
#include <vector>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int n, m;

vector<int> s1;
vector<int> s2;

int dp[1025][1025];

int main()
{
    cin >> n >> m;
    s1.resize(n);
    s2.resize(m);

    for (int i = 0; i < n; i++) cin >> s1[i];
    for (int i = 0; i < m; i++) cin >> s2[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

    int i = n, j = m;
    vector<int> rez;
    while (i >= 1 && j >= 1)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            rez.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else if (dp[i][j - 1] > dp[i - 1][j]) j--;
        else i--;
    }
    
    cout << dp[n][m] << '\n';
    for (int k = rez.size()-1; k >= 0; k--) cout << rez[k] << " ";

}
#include <fstream>
#include <vector>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int dp[1025][1025];

vector < int > v1;
vector < int > v2;
vector < int > v;

int main()
{
    v1.resize(1025);
    v2.resize(1025);
    v.resize(1025);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> v1[i];
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> v2[i];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(v1[i] == v2[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else 
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m] << '\n';
    int l = dp[n][m];
    for(int i = n; i > 0; i--)
    {
        for(int j = m; j > 0; j--)
        {
            if(dp[i][j] == l && v1[i] == v2[j])
            {
                v[l] = v1[i];
                l--;
            }
        }
    }
    for(int i = 1; i <= dp[n][m]; i++)
    {
        cout << v[i] << " "; 
    }
    return 0;
}
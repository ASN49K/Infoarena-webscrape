#include <bits/stdc++.h>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int a[1005], b[1005], dp[1005][1005];
vector <int> v;
int main()
{
    int n, m;
    in >> n >> m;
    for(int i = 1; i <= n; i++)
        in >> a[i];
    for(int i = 1; i <= m; i++)
        in >> b[i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    out << dp[n][m] << '\n';
    int j = m;
    for(int i = n; i > 0; i += 0)
    {
        if(a[i] == b[j])
        {
            v.push_back(a[i]);
            i--, j--;
        }
        else if(dp[i - 1][j] < dp[i][j - 1])
            j--;
        else
            i--;
    }
    for(int i = v.size() - 1; i >= 0; i--)
        out << v[i] << " ";
    return 0;
}

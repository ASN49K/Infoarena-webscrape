#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1024],b[1024],n,m;
string dp[1024][1024];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    for(int i = 1; i <= m; i++)
        fin >> b[i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i] == b[j])
            {
                char c = char(a[i]);
                dp[i][j] = dp[i-1][j-1] + c;
            }
            else
            {
                if(dp[i-1][j].size() > dp[i][j-1].size())
                    dp[i][j] = dp[i-1][j];
                else if(dp[i][j-1].size() > dp[i-1][j].size())
                    dp[i][j] = dp[i][j-1];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
    }
    fout << dp[n][m].size() << '\n';
    for(char c : dp[n][m])
        fout << (int)c << ' ';
    return 0;
}

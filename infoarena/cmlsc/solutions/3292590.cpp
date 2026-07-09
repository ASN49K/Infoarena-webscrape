#include<bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1030], b[1030], dp[1030][1030];
int main()
{
    int n, m;
    fin >> n >> m;
    for(int i = 1; i <= n; ++i)
        fin >> a[i];
    for(int i = 1; i <= m; ++i)
        fin >> b[i];

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    fout << dp[n][m] << "\n";
    int cnt = 1;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(a[i] == b[j] && cnt == dp[n][j])
            {
                fout << a[i] << " ";
                cnt++;
                break;
            }
        }
    }
    fout << "\n";
    return 0;
}
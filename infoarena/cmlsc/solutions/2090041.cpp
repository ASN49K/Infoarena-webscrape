#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NMAX = (1 << 10) + 5;

int dp[NMAX][NMAX];
int n,m,a[NMAX],b[NMAX];

pair <int , int> nextt[NMAX][NMAX];

int main()
{
    fin >> n >> m;
    int i,j;
    for(i=1;i<=n;i++)
    {
        fin >> a[i];
    }
    for(i=1;i<=m;i++)
    {
        fin >> b[i];
    }

    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            if (a[i] == b[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                nextt[i][j].first=i-1;
                nextt[i][j].second=j-1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if(dp[i-1][j]<dp[i][j-1])
                {
                    nextt[i][j].first=i;
                    nextt[i][j].second=j-1;
                }
                else
                {
                    nextt[i][j] = {i - 1, j}; /// insert pair mai usor;
                }
            }
    fout << dp[n][m] << '\n';
    pair<int, int> x = {n, m};
    vector<int>sol;
    while (x.first != 0 && x.second != 0)
    {
        if (nextt[x.first][x.second] == make_pair(x.first - 1, x.second - 1))
            sol.push_back(a[x.first]);
        x = nextt[x.first][x.second];
    }
    reverse(sol.begin(), sol.end());
    for(int i = 0; i < sol.size(); i++)
    {
        fout << sol[i] << ' ';
    }
    return 0;
}

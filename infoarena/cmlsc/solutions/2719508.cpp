#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m;
int v[10251];
int w[10251];
int dp[1030][1030];

int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i ++)
    {
        fin >> v[i];
    }
    for(int i = 1; i <= m; i ++)
    {
        fin >> w[i];
    }
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            if(v[i] == w[j])
            {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    fout << dp[n][m] << '\n';
    stack<int> stiva;
    int k = dp[n][m];
    while(k)
    {
        if(v[n] == w[m])
        {
            stiva.push(v[n]);
            n--;
            m--;
            k--;
        }
        else
        {
            if(dp[n][m] == dp[n-1][m])
            {
                n--;
            }
            else
            {
                m--;
            }
        }
    }
    while(!stiva.empty())
    {
        fout << stiva.top() << ' ';
        stiva.pop();
    }
    fout << '\n';
    return 0;
}

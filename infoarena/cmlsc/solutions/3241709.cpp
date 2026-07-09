#include <bits/stdc++.h>

const std :: string FILENAME = "cmlsc";

std :: ifstream in (FILENAME + ".in");

std :: ofstream out (FILENAME + ".out");

const int NMAX = 11e2 + 5;

int n;

int m;

int a[NMAX];

int b[NMAX];

int dp[NMAX][NMAX];

std :: stack <int> s;

int main()
{

    in >> n >> m;;

    for(int i = 1; i <= n; i ++)
    {
        in >> a[i];
    }

    for(int i = 1; i <= m; i ++)
    {
        in >> b[i];
    }

    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            if(a[i] == b[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }

            dp[i][j] = std :: max({dp[i][j], dp[i - 1][j], dp[i][j - 1]});
        }
    }

    out << dp[n][m] << '\n';

    int i = n;

    int j = m;

    while(i && j)
    {
        if(a[i] == b[j])
        {
            s.push(i);

            i --;

            j --;

            continue;
        }

        if(dp[i - 1][j] > dp[i][j - 1])
        {
            i --;
        }
        else
        {
            j --;
        }
    }

    while(!s.empty())
    {
        out << a[s.top()] << " ";

        s.pop();
    }

    return 0;
}

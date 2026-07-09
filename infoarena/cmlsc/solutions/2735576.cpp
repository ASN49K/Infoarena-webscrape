#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1030], b[1030];
int dp[1030][1030];
int n, m;
int sol[1030], top;

int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    for(int j = 1; j <= m; j++)
        fin >> b[j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max( dp[i - 1][j], dp[i][j - 1] );
        }
    fout << dp[n][m] << "\n";
    int x = n, y = m;
    while(dp[x][y])
    {
        if(a[x] == b[y])
        {
            sol[++top] = a[x];
            x--;
            y--;
        }
        else if(dp[x - 1][y] > dp[x][y - 1])
            x--;
        else y--;
    }
    while(top)
        fout << sol[top--] << " ";

    return 0;
}

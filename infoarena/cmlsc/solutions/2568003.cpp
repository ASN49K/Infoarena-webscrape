#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int Nmax = 1025;

int n, m;
int a[Nmax], b[Nmax];
int dp[Nmax][Nmax];

int main()
{
    fin >> n >> m;

    for(int i = 1; i <= n; i++)
        fin >> a[i];

    for(int i = 1; i <= m; i++)
        fin >> b[i];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);


    fout << dp[n][m] << "\n";


    int x, y, ok;

    x = y = 1;
    for(int pas = 1; pas <= dp[n][m]; pas++)
    {
        ok = 1;
        for(int i = x; i <= n && ok; i++)
            for(int j = y; j <= m && ok; j++)
                if(dp[i][j] == pas && a[i] == b[j])
                {
                    x = i;
                    y = j;
                    ok = 0;
                }

        fout << a[x] << " ";
    }

    fin.close();
    fout.close();
    return 0;
}

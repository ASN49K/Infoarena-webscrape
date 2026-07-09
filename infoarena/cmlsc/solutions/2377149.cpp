#include <bits/stdc++.h>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

short const Nmax = 1025;
int dp[Nmax][Nmax];
int a[Nmax], b[Nmax];
int n, m;

void Read()
{
    int i;
    fin >> n >> m;
    for (i = 1 ; i <= n ; i++)
        fin >> a[i];
    for (i = 1 ; i <= m ; i++)
        fin >> b[i];
    fin.close();
}

void DP()
{
    int i, j;
    for (i = 1 ; i <= n ; i++)
    {
        for (j = 1 ; j <= m ; j++)
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
        else dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
    }
}

void Write(int i , int j)
{
    if (!i || !j) return;
    if (a[i] == b[j])
    {
        Write(i - 1 , j - 1);
        fout << a[i] << " ";
    }
    else if (dp[i - 1][j] < dp[i][j - 1]) Write(i , j - 1);
    else Write(i - 1 , j);
}

int main()
{
    Read();
    DP();
    fout << dp[n][m] << "\n";
    Write(n , m);
    fout.close();
    return 0;
}

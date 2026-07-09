#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m;
int a[1050], b[1050], dp[1050][1050], sol[1050], k;

void Read()
{
    int i;
    fin >> n >> m;
    for(i = 1; i <= n; i++)
        fin >> a[i];
    for(i = 1; i <= m; i++)
        fin >> b[i];
    fin.close();
}

void Vector(int n, int m)
{
    if(n < 1 || m < 1) return;
    if(a[n] == b[m])
        sol[++k] = a[n], Vector(n - 1, m - 1);
    else
    {
        if(dp[n - 1][m] > dp[n][m - 1])
            Vector(n - 1, m);
        else Vector(n, m - 1);
    }
}

void Solve()
{
    int i, j;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    fout << dp[n][m] << "\n";
    Vector(n, m);
    for(i = k; i >= 1; i--)
        fout << sol[i] << " ";
    fout.close();
}

int main()
{
    Read();
    Solve();
    return 0;
}

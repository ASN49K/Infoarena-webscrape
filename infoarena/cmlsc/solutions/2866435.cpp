#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m;
int a[1025], b[1025], dp[1025][1025], rasp[1025], cnt;
void Citire()
{
    int i;
    fin >> n >> m;
    for(i = 1;i <= n;i++)
        fin >> a[i];
    for(i = 1;i <= m;i++)
        fin >> b[i];
}

void Solve()
{
    int i, j;
    for(i = 1;i <= n;i++)
        for(j = 1;j <= m;j++)
        {
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    fout << dp[n][m] << "\n";
    i = n;
    j = m;
    while(i >= 1 && j >= 1)
    {
        if(a[i] == b[j])
        {
            rasp[++cnt] = a[i];
            i--;
            j--;
        }
        else if(dp[i - 1][j] >= dp[i][j - 1])
            i--;
        else
            j--;
    }
    for(i = cnt;i >= 1;i--)
        fout << rasp[i] << " ";
}
int main()
{
    Citire();
    Solve();
    return 0;
}

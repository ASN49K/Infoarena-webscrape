#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, a[1030], b[1030], dp[1030][1030];

int main()
{
    int i, j;
    fin >> n >> m;
    for(i = 1; i <= n; i++)
        fin >> a[i];
    for(j = 1; j <= m; j++)
        fin >> b[j];
    for(i = n; i >= 1; i--)
        for(j = m; j >= 1; j--)
        {
            if(a[i] == b[j])
            dp[i][j] = 1 + dp[i + 1][j + 1];
            else dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }

    fout << dp[1][1] << "\n";
    i = j = 1;
    while(dp[i][j] != 0)
    {
        if(a[i] == b[j])
        {
            fout << a[i] << " ";
            i++; j++;
        }
        else if(dp[i + 1][j] > dp[i][j + 1]) i++;
        else j++;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
///concurs
///restmare

int n, a[1030], b[1030], dp[1030][1030], m;

int main()
{
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    fout.tie(0);
    int i, j;
    fin >> n >> m;
    for(i=1;i<=n;i++)
        fin >> a[i];
    for(i=1;i<=m;i++)
        fin >> b[i];
    for(i=n;i>=1;i--)
        for(j=n;j>=1;j--)
        if(a[i] == b[j]) dp[i][j] = 1 + dp[i+1][j+1];
    else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
    fout << dp[1][1] << "\n";
    i = j = 1;
    while(i <= n && j <= m)
    {
        if(a[i] == b[j])
        {
            fout << a[i] << " ";
            i++;
            j++;
        }
        else if(dp[i+1][j] > dp[i][j+1]) i++;
        else j++;
    }
    fin.close();
    fout.close();
    return 0;
}

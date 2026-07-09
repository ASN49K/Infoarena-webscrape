#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m;
int a[1030],b[1030],dp[1030][1030],t[1030];
int main()
{
    int i,j,cnt=0;
    fin >> n >> m;
    for (i=1; i<=n; i++)
        fin >> a[i];
    for (i=1; i<=m; i++)
        fin >> b[i];
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if (a[i]==b[j]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
        }
    fout << dp[n][m] << "\n";
    for (i=n, j=m; i;)
    {
        if (a[i]==b[j]) {t[++cnt]=a[i]; i--; j--;}
        else if (dp[i-1][j]<=dp[i][j-1]) j--;
        else i--;
    }
    for (i=cnt; i>=1; i--)
        fout << t[i] << " ";
    return 0;
}

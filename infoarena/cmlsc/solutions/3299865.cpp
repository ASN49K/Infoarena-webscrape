#include <bits/stdc++.h>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int n, m, a[1030], b[1030], dp[1030][1030];

void afis (int i, int j, int k)
{
    if (i==0 || j==0)
    {
        fout << k << '\n';
        return;
    }
    if (a[i]==b[j])
    {
        afis(i-1,j-1,k+1);
        fout << a[i] << " ";
    }
    else if (dp[i-1][j]>dp[i][j-1])
        afis(i-1,j,k);
    else
        afis(i,j-1,k);
}

int main ()
{
    fin >> n >> m;
    for (int i=1; i<=n; i++)
        fin >> a[i];
    for (int i=1; i<=m; i++)
        fin >> b[i];
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    afis(n,m,0);
    return 0;
}

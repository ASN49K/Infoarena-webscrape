#include <bits/stdc++.h>
using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
const int Nmax = 1025;
int a[Nmax], b[Nmax],n,i,j,m,ind,dp[Nmax][Nmax],ans[Nmax];

void constr()
{
    while(n && m)
        {
            if(a[n] == b[m])
            {
                n--;
                m--;
                ans[++ind] = a[n];
            }
            else
                if(dp[n-1][m] > dp[n][m-1])
                    n--;
                else
                    m--;
        }
}
int main()
{
    fin >> n >> m;
    for(i=1; i<=n; i++) fin>>a[i];
    for(j=1; j<=m; j++) fin>>b[j];

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if(a[i] == b[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }

    fout<<dp[n][m]<<'\n';
    int len = dp[n][m];

    constr();
    reverse(ans+1, ans+len+1);
    for(i=1; i<=len; i++)
        fout<<ans[i]<<' ';

    return 0;
}





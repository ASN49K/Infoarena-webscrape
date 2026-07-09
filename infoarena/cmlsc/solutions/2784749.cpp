/*
#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int NMAX = 1030;
int  dr[NMAX], dp[NMAX][NMAX];
int main()
{
    int a[NMAX], b[NMAX], m, n;

    in >> m >> n;
    for(int i = 1;i <= m;i ++)
    {
        in >> a[i];
    }
    for(int j = 1;j <= n;j ++)
    {
        in >> b[j];
    }

   int k = 0;
   for(int i = 1;i <= m;i ++)
    for(int j = 1;j <= n;j ++)
   {
       if(a[i] == b[j])
       {
           dp[i][j] = dp[i - 1][j - 1] + 1;
           dr[k ++] = a[i];
       }
       else{
        dp[i][j] = max(dp[i-1][j], dp[i][j - 1]);
       }
   }

    out << dp[m][n] << "\n";
    for(int i = 0;i < k;i ++)
        out << dr[i] <<" ";

    return 0;
}
*/

#include <bits/stdc++.h>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int i,m,n,nr,j,rez[1030],a[1030],b[1030],dp[1030][1030];
int main()
{
    in>>n;
    in>>m;

    for(i=1; i<=n; i++)
    {
        in>>a[i];

    }
    for(i=1; i<=m; i++)
    {
        in>>b[i];
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
        }
    }
    out<<dp[n][m]<<'\n';
    i=n;
    j=m;
    while(i>0&&j>0)
    {
        if(a[i]==b[j])
        {
            rez[++nr]=a[i];
            i--;
            j--;

        }
        else if(dp[i][j]==dp[i-1][j])
        {
            i--;
        }
        else j--;
    }
    for(i=nr; i>0; i--)
    {
        out<<rez[i]<<" ";
    }
    return 0;
}

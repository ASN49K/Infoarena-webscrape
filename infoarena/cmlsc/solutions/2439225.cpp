#include <bits/stdc++.h>
#define maxim 1030

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

void afis ( int i , int j, int (&a)[maxim], int (&b)[maxim], int (&dp)[maxim][maxim])
{

   if (i == 0 || j == 0)
       return ;
   if (a[i] == b[j])
   {
       afis (i - 1, j - 1, a, b, dp);
       g << a[i]<< " ";
   }
   else
       if (dp[i - 1][j] >= dp[i][j - 1])
           afis (i - 1, j, a, b, dp);
       else
           afis (i, j - 1, a, b, dp);

}

int main()
{
    int n, m;
    int  a[maxim], b[maxim], dp[maxim][maxim];
    f >> n >> m;

    for (int i = 1; i <= n; ++ i)
        f>>a[i];

    for (int j = 1; j <=m; ++ j)
        f>>b[j];

    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j)
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max (dp[i - 1][j], dp[i][j - 1] );

    g << dp[n][m] << '\n';
    afis(n, m, a, b, dp);

}
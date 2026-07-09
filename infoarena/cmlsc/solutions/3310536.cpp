#include <bits/stdc++.h>
#define NMAX 1025
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

short a[NMAX], b[NMAX];
short dp[NMAX][NMAX]; ///LCS
short subsir[NMAX]; ///subsirul cerut

int main()
{
    int n, m;
    in >> n >> m;
    for(int i=1; i<=n; i++)
        in >> a[i];
    for(int j=1; j<=m; j++)
        in >> b[j];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
        }
    }
    out << dp[n][m] << "\n"; ///afisam lungimea subsirului

    int lungime=dp[n][m], x=n, y=m; ///reconstruim subsirul
    while(lungime>0)
    {
        if(a[x]==b[y])
        {
            subsir[lungime--]=a[x];
            x--;
            y--;
        }
        else
        {
            if(dp[x-1][y]==dp[x][y])
                x--;
            else
                y--;
        }
    }
    for(int i=1; i<=dp[n][m]; i++) ///afisam subsirul
        out << subsir[i] << " ";

    return 0;
}

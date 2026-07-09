#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m;
int v1[1050], v2[1050];
int dp[1050][1050];

void dinamic()
{
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (v1[i]==v2[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;

            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
}

void recursiv(int l, int c)
{
    if (dp[l][c]==0)
        return;

        if (v1[l]==v2[c])
        {
            recursiv(l-1,c-1);
            g <<v1[l] <<' ';
        }
        else
        {
            if (dp[l-1][c]==dp[l][c])
            {
                recursiv(l-1,c);
            }
            else
                recursiv(l,c-1);
        }

}

int main()
{
    f >> n >> m;
    for (int i=1; i<=n; i++)
        f >> v1[i];
    for (int i=1; i<=m; i++)
        f >> v2[i];
    dinamic();
    g << dp[n][m] << '\n';
    recursiv(n,m);

    return 0;
}

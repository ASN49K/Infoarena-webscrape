#include <iostream>
#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

long long dp[1025][1025];
int a[1025], b[1025];


int main()
{
    int n, m;
    in>>n>>m;

    for(int i=1; i<=n; i++)
        in>>a[i];
    for(int i=1; i<=m; i++)
        in>>b[i];


    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
            {
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int sir[1025], k=dp[n][m];
    int i=n;
    int j=m;
    while(i>0 && j>0)
    {
        if(a[i]==b[j])
        {
            sir[k] = a[i];
            --i;--j;--k;
        }
        else if(dp[i-1][j] < dp[i][j-1])
            --j;
        else
            --i;


    }
    out<<dp[n][m]<<'\n';
    for(i=1; i<=dp[n][m]; i++)
        out<<sir[i]<<' ';
    return 0;
}

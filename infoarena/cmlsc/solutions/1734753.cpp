#include <iostream>
#include <fstream>
#define LL long long
using namespace std;
ifstream f("cmmdc.in");
ofstream g("cmmdc.out");
short v[1025], w[1025], dp[1025][1025], k[1025];
int n, m;
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> v[i];
    for(int i=1;i<=m;i++)
        cin >> w[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(v[i]==w[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    int i=n, j=m, nr=0;
    while(dp[i][j]!=0)
    {
        if(dp[i-1][j] == dp[i][j])
            i--;
        else if(dp[i][j-1] == dp[i][j])
                j--;
        else if(dp[i-1][j-1]<dp[i][j])
        {
            k[++nr]=v[i];
            i--;
            j--;
        }
    }
    cout << dp[n][m] << '\n';
    for(int i=nr;i>=1;i--)
        cout << k[i] <<' ';
    return 0;
}

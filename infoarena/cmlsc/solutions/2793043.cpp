#include <fstream>
using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int dp[1025][1025], n, a[1025], m, b[1025];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    for(int i=0;i<=n;i++)
        dp[i][0]= 0;
    for(int j=0;j<=m;j++)
        dp[0][j] = 0;
    for(int i=1;i<=n;i++)
    {

        for(int j=1;j<=m;j++)
        {
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout<<dp[n][m]<<"\n";
    for(int i=1, k = 0;i<=m;i++)
            if(dp[n][i] != k)
            {
                k++;
                cout<<b[i]<<' ';
            }
    return 0;
}

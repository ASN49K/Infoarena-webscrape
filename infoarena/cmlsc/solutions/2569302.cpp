#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int dp[1026][1026];
int n , m;
int a[1026], b [1026];
int sol[1026];
int main() {
    cin >> n >> m;
    for( int i =1 ;i <=n;i ++)
        cin >>a[i];
    for( int j =1 ;j <=m;j ++)
        cin >> b[j];
    for( int i =1 ;i <=n;i ++)
        for( int j =1 ;j<=m;j ++)
        {
            if(a[i] == b[j])
                dp[i][j] =1 + dp[i - 1][j - 1];
            else
            {
                dp[i][j] = max(dp[i -1][j], dp[i][j - 1]);
            }
        }
    cout << dp[n][m]<<'\n';

    int start = dp[n][m], stop = dp[n][m];
    while(start)
    {
        if(a[n] == b[m])
        {

            sol[dp[n][m]] = a[n];
            start--;
            n--;
            m--;
        }
        else
        if(dp[n -1][m] > dp[n][m - 1])
            n--;
        else
            m--;
    }
    for( int i = 1; i <= stop; i++)
        cout << sol[i]<<" ";
    return 0;
}

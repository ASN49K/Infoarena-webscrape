#include <fstream>

using namespace std;

ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");

const int lim = 1050;
int n, m, dp[lim][lim], a[lim], b[lim], sol[lim];

int main()
{
    cin>>n>>m;
    for(int i = 1; i <= n; ++i)
        cin>>a[i];
    for(int i = 1; i <= m; ++i)
        cin>>b[i];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            if(a[i] == b[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    cout<<dp[n][m]<<"\n";
    int i = n, j = m;
    while(i > 0 and j > 0)
    {
        if(a[i] == b[j])
        {
            sol[0]++;
            sol[sol[0]] = a[i];
            --i;
            --j;
        }
        else
        {
            if(dp[i-1][j] > dp[i][j-1])
                --i;
            else
                --j;
        }
    }
    for(int i = sol[0]; i >= 1; --i)
        cout<<sol[i]<<" ";
    return 0;
}

#include <fstream>
#include <vector>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int dp[1030][1030],a[1030],b[1030];
vector < int > ans;

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int i=1; i<=m; i++)
        cin>>b[i];
    dp[0][0] = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int aux=dp[n][m];
    cout<<aux<<'\n';
    ans.resize(aux);
    while(aux>0)
    {
        if (dp[n - 1][m] == aux)
            n--;
        else if (dp[n][m - 1] == aux)
            m--;
        else
        {

            ans[--aux]=a[n];
            n--;
            m--;
        }
    }
    for(auto i : ans)
        cout<<i<<" ";
}

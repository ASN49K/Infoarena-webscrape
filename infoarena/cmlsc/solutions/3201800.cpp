#include <fstream>
#include <vector>
#include <stack>
#define f first
#define s second
const int NMAX=1055;

using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

struct dp
{
    int val, i, j;
} dp[NMAX][NMAX];
int n, m, a[NMAX], b[NMAX];

void dfs(int, int);

int main()
{
    int i, j;
    cin>>n>>m;
    for(i=1; i<=n; i++) cin>>a[i];
    for(i=1; i<=m; i++) cin>>b[i];
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(dp[i][j].val<dp[i][j-1].val)
            {
                dp[i][j].val=dp[i][j-1].val;
                dp[i][j].i=i;
                dp[i][j].j=j-1;
            }
            if(dp[i][j].val<dp[i-1][j].val)
            {
                dp[i][j].val=dp[i-1][j].val;
                dp[i][j].i=i-1;
                dp[i][j].j=j;
            }
            if(a[i]==b[j])
            {
                if(dp[i][j].val<dp[i-1][j-1].val+1)
                {
                    dp[i][j].val=dp[i-1][j-1].val+1;
                    dp[i][j].i=i-1;
                    dp[i][j].j=j-1;
                }
            }
        }
    }
    cout<<dp[n][m].val<<'\n';
    dfs(n, m);
    return 0;
}

void dfs(int n, int m)
{
    if(n==0 || m==0) return;
    dfs(dp[n][m].i, dp[n][m].j);
    if(a[n]==b[m]) cout<<a[n]<<' ';
}

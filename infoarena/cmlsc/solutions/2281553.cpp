#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

const string FILENAME="cmlsc";

#define OpenIN() freopen((FILENAME+".in").c_str(),"r",stdin)
#define OpenOUT() freopen((FILENAME+".out").c_str(),"w",stdout)
#define OpenALL() OpenIN(), OpenOUT()
#define infoarena() OpenALL()

const int N=1024+5;

int n,a[N];
int m,b[N];

int dp[N][N];
pair<int,int>dad[N][N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    infoarena();
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                dad[i][j]={i-1,j-1};
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1])
                {
                    dp[i][j]=dp[i-1][j];
                    dad[i][j]={i-1,j};
                }
                else
                {
                    dp[i][j]=dp[i][j-1];
                    dad[i][j]={i,j-1};
                }
            }
        }
    }
    cout<<dp[n][m]<<"\n";
    pair<int,int>now={n,m};
    vector<int>ans;
    while(ans.size()<dp[n][m])
    {
        if(a[now.first]==b[now.second])
        {
            ans.push_back(a[now.first]);
        }
        now=dad[now.first][now.second];
    }
    reverse(ans.begin(),ans.end());
    for(auto &x:ans)
    {
        cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
}
/**



**/

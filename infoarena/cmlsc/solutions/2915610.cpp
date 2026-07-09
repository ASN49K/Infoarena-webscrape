#include <fstream>
#define N_max 1025
using namespace std;
ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");
int n,m,v[N_max],w[N_max];
int dp[N_max][N_max];
void Search(int is,int js)
{
    if(is && js)
    {
        if(v[is]==w[js])
        {
            Search(is-1,js-1);
            cout<<v[is]<<" ";
        }
        else if(dp[is-1][js]>dp[is][js-1]) Search(is-1,js);
        else Search(is,js-1);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>v[i];
    for(int i=1;i<=m;++i) cin>>w[i];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(v[i]==w[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    cout<<dp[n][m]<<'\n';
    Search(n,m);
}

#include <fstream>
using namespace std;
ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");
int dp[1025][1025],a[1025],b[1025],n,m;
void CMLSC (int i,int j)
{

    if(i==0 || j==0) return;
    else
    {
        if(a[i]==b[j])
        {
            CMLSC(i-1,j-1);
            cout<<a[i]<<" ";
        }
        else if(dp[i-1][j]<dp[i][j-1])
        {
            CMLSC(i,j-1);
        }
        else CMLSC(i-1,j);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; ++i) cin>>a[i];
    for(int i=1; i<=m; ++i) cin>>b[i];
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
        {
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    cout<<dp[n][m];
    cout<<endl;
    CMLSC(n,m);
}

#include <fstream>

using namespace std;

ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");

int dp[1025][1025], a[1025], b[1025], v[1025];

int main() {

    int n,m,i,j;
    cin>>m>>n;
    for(i=1;i<=m;i++) cin>>a[i];
    for(i=1;i<=n;i++) cin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
        if(b[i]==a[j])
            dp[i][j]=max(dp[i][j], dp[i-1][j-1])+1;
    }
    cout<<dp[n][m]<<'\n';
    int k=dp[n][m];
    i=n;
    j=m;
    while(k>0)
    {
        if(a[j]==b[i])
        {
            v[k]=a[j];
            k--;
            i--;
            j--;
        }
        else
        {
            if(dp[i][j-1]==k) j--;
            else i--;
        }
    }
    for(i=1;i<=dp[n][m];i++)
        cout<<v[i]<<" ";
    return 0;
}

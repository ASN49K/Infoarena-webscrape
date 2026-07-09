#include <fstream>

using namespace std;
fstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int m,n,i,j,mx,a[1050],b[1050],dp[1050][1050], sol[1050],k;
int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=m;i++)
        cin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(a[i]==b[j])
            dp[i][j]=dp[i-1][j-1]+1;
        else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    }

    i=n;
    j=m;
    while(i&&j)
    {
        if(dp[i][j]==dp[i-1][j-1]+1)
        {
            sol[++k]=a[i];
            i--;j--;
        }
        else if(dp[i-1][j]==dp[i][j])
        {
            i--;
        }
        else j--;
    }

    cout<<dp[n][m]<<endl;
    for(i=k;i>=1;i--)
        cout<<sol[i]<<" ";

    return 0;
}

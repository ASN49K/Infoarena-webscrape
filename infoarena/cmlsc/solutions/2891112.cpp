#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n,p,m,a[1050],b[1050],dp[1050][1050],v[1050],k;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    k=dp[n][m];
    cout<<k<<endl;
    int i=n,j=m;
    while(i>0 && j>0)
    {
        if(a[i]==b[j])
        v[k--]=a[i],i--,j--;
        else
        if(dp[i-1][j]>dp[i][j-1]) i--;
        else j--;
    }
    for(int i=1;i<=dp[n][m];i++)
        cout<<v[i]<<' ';
    return 0;
}

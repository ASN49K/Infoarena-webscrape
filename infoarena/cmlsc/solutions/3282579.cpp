#include <fstream>

using namespace std;

ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");

int n,m,a[2005],b[2005],dp[2005][2005],ans[2005],nr;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    int i=n,j=m;
    while(i && j)
    {
        if(a[i]==b[j])
        {
            ans[++nr]=a[i];
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    cout<<nr<<'\n';
    for(int i=nr;i>=1;i--)
        cout<<ans[i]<<' ';
    return 0;
}

#include <fstream>
#include <cstring>
using namespace std;

ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");

int i,j,n,m,dp[1025][1025],a[1025],b[1025],k,c[1025];

int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=m;i++)
        cin>>b[i];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    i=n;
    j=m;
    while(i && j)
    {
        if(a[i]==b[j])
        {
            c[++k]=a[i];
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
    cout<<k<<endl;
    for(i=k;i>=1;i--)
        cout<<c[i]<<' ';
}

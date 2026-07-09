#include <fstream>

using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
short int a[1025],b[1025],dp[1025][2025],r[1025];
int main()
{
    short int m,n;
    cin>>m>>n;
    for(int i=1; i<=m; i++)
    {
        cin>>a[i];
    }
    for(int j=1; j<=n; j++)
    {
        cin>>b[j];
    }
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[m][n]<<'\n';
    int t=dp[m][n];
    int k=0;
    int i=m;
    int j=n;
    while(i>1 || j>1)
    {
        if(dp[i][j]==dp[i-1][j-1]+1)
        {
            cout << i << ' ' << j << '\n';
            r[t]=a[i];
            i--;
            j--;
            t--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    for(int i=1;i<=dp[m][n];i++)
    {
        cout<<r[i]<<" ";
    }
    return 0;
}

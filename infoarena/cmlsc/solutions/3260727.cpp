#include <iostream>

using namespace std;
//ifstream cin("cmlsc.in");
//ofstream cout("cmlsc.out");
long long a[1025],b[1025],dp[1025][2025],r[257];
int f[301];
int main()
{
    int m,n;
    cin>>m>>n;
    for(int i=1; i<=m; i++)
    {
        cin>>a[i];
        f[a[i]]++;
    }
    for(int j=1; j<=n; j++)
    {
        cin>>b[j];
        f[b[j]]++;
    }
    dp[0][0]=0;
    dp[0][1]=0;
    dp[1][0]=0;
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
    cout<<dp[m][n]<<endl;
    int t=dp[m][n];
    int k=0;
    if(n>=m)
    {
        for(int i=1; i<=n; i++)
        {
            if(f[a[i]]==2)
            {
                cout<<a[i]<<" ";
            }
        }
    }
    else
    {
        for(int i=1; i<=m; i++)
        {
            if(f[b[i]]==2)
            {
                cout<<b[i]<<" ";
            }
        }
    }
    return 0;
}

#include <fstream>

using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int dp[1025][1025],a[1025],b[1025];
void afisare(int i, int j)
{
    if(dp[i][j]>0)
    {
        if(a[i]==b[j])
        {
            afisare(i-1,j-1);
            cout<<a[i]<<" ";
        }
        else
        {
            if(dp[i-1][j]>=dp[i][j-1])
                afisare(i-1,j);
            else
                afisare(i,j-1);
        }
    }
}
int main()
{
    int n,m,i,j;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=m;i++)
        cin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]!=b[j])
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            else
                dp[i][j]=dp[i-1][j-1]+1;
    cout<<dp[n][m]<<'\n';
    afisare(n,m);
    return 0;
}

#include <fstream>
#include <vector>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int n,m,i,j,v1[1100],v2[1100],maxim,dp[1100][1100];
vector<int>v;

int main()
{
    cin>>n>>m;
    for(i=1; i<=n; i++)
        cin>>v1[i];
    for(i=1; i<=m; i++)
        cin>>v2[i];
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(v1[i]==v2[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout << dp[n][m]<< endl;
    i=n;
    j=m;
    while(dp[i][j]!=0)
    {
        if(v1[i]==v2[j])
        {
            v.push_back(v1[i]);
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
    n=v.size();
    for(i=n-1;i>=0;i--)
        cout<<v[i]<<" ";
    return 0;
}

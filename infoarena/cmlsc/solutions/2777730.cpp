#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int a[1025],b[1025],dp[1025][1025];
void afis(int l,int c)
{
    if(!l || !c)
       return;
    if(a[l]==b[c])
    {
        afis(l-1,c-1);
        cout<<a[l]<<" ";
    }
    else if(a[l]!=b[c])
    {
        if(dp[l-1][c]>dp[l][c-1])
           afis(l,c-1);
        else if(dp[l-1][c]<=dp[l][c-1])
        {
            if(l-1>=c)
               afis(l-1,c);
            else if(l-1<c)
                    afis(l,c-1);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
               dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[n][m]<<'\n';
    afis(n,m);
    return 0;
}

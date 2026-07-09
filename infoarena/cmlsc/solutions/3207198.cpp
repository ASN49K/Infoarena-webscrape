#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int n,m,i,j,a[1030],b[1030],dp[1030][1030],ok;

void afis(int i,int j)
{
    if(dp[i][j]==0)
        return;
    if(a[i]==b[j])
    {
        afis(i-1,j-1);
        cout<<a[i]<<" ";
        return;
    }
    if(dp[i][j-1]>dp[i-1][j])
        afis(i,j-1);
    else
        afis(i-1,j);
}

int main()
{
    cin>>n>>m;
    for(i=1; i<=n; i++)
        cin>>a[i];
    for(j=1; j<=m; j++)
        cin>>b[j];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++,ok=0)
        {
            if(a[i]==b[j])
                ok=1;
            dp[i][j]=max(dp[i-1][j-1]+ok,max(dp[i-1][j],dp[i][j-1]));
        }
    cout << dp[n][m] << endl;
    afis(n,m);
    return 0;
}

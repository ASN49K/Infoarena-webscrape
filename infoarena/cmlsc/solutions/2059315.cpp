#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
const int nm=1024;
int dp[nm+5][nm+5],n,m,v1[nm+5],v2[nm+5],val;
void afisare(int r,int c)
{
    if(r==0 or c==0)
        return;
    if(v1[r]==v2[c])
    {
        afisare(r-1,c-1);
        cout<<v1[r]<<" ";
    }
    else
        if(dp[r-1][c]>dp[r][c-1])
            afisare(r-1,c);
        else
            afisare(r,c-1);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>v1[i];
    for(int i=1;i<=m;i++)
        cin>>v2[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(v1[i]==v2[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    cout<<dp[n][m]<<"\n";
    afisare(n,m);
    return 0;
}

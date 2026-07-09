#include <fstream>
#include <cmath>
using namespace std;
ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");

const int max_n=1026;
int dp[max_n][max_n];

int main()
{
    int n,m, v1[max_n], v2[max_n];
    cin>>n>>m;

    for(int i=1;i<=n;i++)
        cin>>v1[i];

    for(int j=1;j<=m;j++)
        cin>>v2[j];

    for(int idx1=1;idx1<=n;idx1++)
        {
            for(int idx2=1;idx2<=m;idx2++)
        if(v1[idx1]==v2[idx2])
        dp[idx1][idx2]=1+dp[idx1-1][idx2-1];
    else
        dp[idx1][idx2]=max(dp[idx1][idx2-1],dp[idx1-1][idx2]);
        }
    cout<<dp[n][m]<<endl;

    int idx1=n;
    int idx2=m;

    int ans[max_n];
    int idx_ans=dp[n][m];

    while(idx1>0 && idx2>0)
    {
        if(v1[idx1]==v2[idx2])
        {
            ans[idx_ans]=v1[idx1];
            idx_ans--;
            idx1--;
            idx2--;
        }
        else if(dp[idx1-1][idx2]>dp[idx1][idx2-1])
            idx1--;
        else
            idx2--;
    }
    for(int idx=1;idx<=dp[n][m];idx++)
        cout<<ans[idx]<<" ";

    return 0;
}

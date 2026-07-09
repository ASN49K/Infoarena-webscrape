#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n,m,A[1055],B[1055],dp[1055][1055],ans[1055];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>A[i];
    for(int i=1;i<=m;i++)
        cin>>B[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(A[i]==B[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    int nr=0;
    int i=n,j=m;
    while(i>=1 && j>=1)
    {
        if(A[i]==B[j])
        {
            nr++;
            ans[nr]=A[i];
            i--;
            j--;
        }
        else if(dp[i-1][j]<dp[i][j-1])
            j--;
        else if(dp[i][j-1]>=dp[i-1][j])
            i--;
    }
    cout<<nr<<"\n";
    for(int i=nr;i>=1;i--)
        cout<<ans[i]<<" ";
    return 0;
}

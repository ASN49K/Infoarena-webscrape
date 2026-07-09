#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int n,m,v1[2000],v2[2000],dp[2000][2000];
bool ans[2000];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v1[i];
    }
    for(int i=1;i<=m;i++){
        cin>>v2[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(v1[i]==v2[j]){
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])+1;
                ans[i]=true;
            }
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    cout<<dp[n][m]<<'\n';
    for(int i=1;i<=n;i++){
        if(ans[i]==true)
            cout<<v1[i]<<" ";
    }
    return 0;
}

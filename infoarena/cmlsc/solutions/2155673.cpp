#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1030],b[1030],c[1030],dp[1030][1030],k;
bool fr[258];


int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++)f>>a[i];
    for(int i=1;i<=m;i++)f>>b[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)if(a[i]==b[j])dp[i][j]=dp[i-1][j-1]+1;
        else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    int l=dp[n][m];
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            if(dp[i][j]==l && a[i]==b[j]){
                c[++k]=a[i];
            }
        }
    }
    g<<dp[n][m]<<'\n';
    for(int i=k;i>=1;i--)g<<c[i]<<" ";
return 0;
}

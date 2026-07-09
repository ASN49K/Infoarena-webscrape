#include <fstream>
std::ifstream f("cmlsc.in");
std::ofstream g("cmlsc.out");
int n,m,i,j,a[1030],b[1030],dp[1030][1030],nr,sol[1030];
int main(){
    f>>n>>m;
    for(i=1;i<=n;f>>a[i++]);
    for(i=1;i<=m;f>>b[i++]);
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)
        if (a[i]==b[j])dp[i][j]=dp[i-1][j-1]+1;
        else dp[i][j]=std::max(dp[i-1][j],dp[i][j-1]);
    for(i=n,j=m;i&&j;){
        while(dp[i-1][j]==dp[i][j])i--;
        while(dp[i][j-1]==dp[i][j])j--;
        nr++,sol[dp[i][j]]=a[i--],j--;
    }
    g<<nr<<'\n';
    for(i=1;i<=nr;g<<sol[i++]<<" ");
}

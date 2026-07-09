#include <fstream>

using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
const int Nmax = 1024;
int dp[Nmax+5][Nmax+5];
int a[Nmax+5],b[Nmax+5],sir[Nmax+5],len;
void Reconst(int i,int j)
{
    if(i<1||j<1)return;
    if(dp[i][j]==dp[i-1][j-1]+1)
    {
        Reconst(i-1,j-1);
        cout<<a[i]<<' ';
    }
    else if(dp[i][j] == dp[i-1][j])Reconst(i-1,j);
    else Reconst(j,i-1);
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int j=1;j<=m;++j)cin>>b[j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            if(a[i]==b[j])dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    cout<<dp[n][m]<<'\n';
    for(int i=n,j=m;i;)
    {
        if(a[i]==b[j])
        {
            sir[++len]=a[i];
            i--;
            j--;
        }
        else if(dp[i-1][j] < dp[i][j-1])j--;
        else i--;
    }
    for(int i=len;i>0;--i)cout<<sir[i]<<' ';
    return 0;
}

#include <fstream>
#define nMax 1028
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, A[nMax], B[nMax], Sol[nMax], nrsol, dp[nMax][nMax];
void read()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>A[i];
    for(int i=1;i<=m;i++)
        fin>>B[i];
}
void solve()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(A[i]==B[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    fout<<dp[n][m]<<'\n';
    for(int i=n, j=m;dp[i][j]>0;)
    {
        if(A[i]==B[j])
        {
            Sol[++nrsol]=A[i];
            i--, j--;
        }
        else
        {
            if(dp[i][j]>dp[i-1][j])
                j--;
            else
                i--;
        }
    }
    for(int i=nrsol;i>=1;i--)
        fout<<Sol[i]<<" ";
}
int main()
{
    read();
    solve();
    return 0;
}

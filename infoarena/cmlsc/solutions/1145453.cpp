#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n,m;
int a[1050],b[1050];
int dp[1050][1050];
int sir[1050];
int main()
{
    in>>n>>m;
    for(int i=1; i<=n; i++) in>>a[i];
    for(int i=1; i<=m; i++) in>>b[i];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    out<<dp[n][m]<<'\n';
    int nrmax=0;
    int i=n,j=m;
    while(i && j)
    {
        if(a[i]==b[j]) sir[++nrmax]=a[i],i--,j--;
        else if(dp[i-1][j]==dp[i][j]) i--;
            else j--;
    }
    for(int i=nrmax; i; i--) out<<sir[i]<<' ';
    out.close();
    return 0;
}

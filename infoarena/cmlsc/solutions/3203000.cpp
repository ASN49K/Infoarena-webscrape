#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[1026][1026], n, m, a[1026], b[1026];
int main()
{
    fin>>n>>m;
    for(int i=0; i<n; i++)
        fin>>a[i];
    for(int i=0; i<m; i++)
        fin>>b[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
        }
    fout<<dp[n][m]<<'\n';
    int rez[1026], k=0;
    int is=n, js=m;
    while(dp[is][js])
    {
        if(dp[is][js]==dp[is-1][js])
            is--;
        else if(dp[is][js]==dp[is][js-1])
            js--;
        else {
            rez[k++]=a[is-1];
            is--, js--;
        }
    }
    for(int i=k-1; i>=0; i--)
        fout<<rez[i]<<" ";
    return 0;
}

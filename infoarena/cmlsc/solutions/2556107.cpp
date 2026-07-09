#include <iostream>
#include <fstream>
#define MAX 1026
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,k,a[MAX],b[MAX],dp[MAX][MAX],sol[MAX];
int main()
{
    fin>>n>>m;
    int i,j;
    for(i=1;i<=n;i++)fin>>a[i];
    for(i=1;i<=m;i++)fin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(a[i]==b[j])
            dp[i][j]=1+dp[i-1][j-1];
        else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    for(i=n,j=m;i;)
    {
        if(a[i]==b[j])
        {
            sol[++k]=a[i];
            i--;j--;
        }
        else if(dp[i-1][j]<dp[i][j-1])
            j--;
        else
            i--;
    }
    fout<<dp[n][m]<<'\n';
    for(i=k;i>=1;i--)fout<<sol[i]<<" ";
    return 0;
}

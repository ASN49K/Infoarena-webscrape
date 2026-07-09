#include <iostream>
#include<fstream>
using namespace std;ifstream fin("cmlsc.in");ofstream fout("cmlsc.out");int a[1025],b[1025],n,m,dp[1025][1025],rsp[1025],lng,i,j;
int main()
{
    fin>>n>>m;for(i=1;i<=n;i++)fin>>a[i];for(i=1;i<=m;i++)fin>>b[i];
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)if(a[i]==b[j])dp[i][j]=dp[i-1][j-1]+1;
    else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    i=n;j=m;while(i&&j){
    if(a[i]==b[j])rsp[++lng]=a[i],i--,j--;
    else if(dp[i-1][j]>=dp[i][j-1])i--;
    else j--;
    }fout<<lng<<'\n';for(i=lng;i>0;i--)fout<<rsp[i]<<' ';
    return 0;
}

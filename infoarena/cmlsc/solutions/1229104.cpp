#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,a[1025],b[1025];
int dp[1025][1025];
int sol[1025],lg;
void lcs()
{
    //dinamica
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    //sirul
    for(int i=n,j=m;i;)
    {
        if(a[i]==b[j]) {sol[++lg]=a[i];i--;j--;}
        else if(dp[i-1][j]<dp[i][j-1]) j--;
            else i--;
    }

}
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++) fin>>a[i];
    for(int i=1;i<=m;i++) fin>>b[i];
    lcs();
    fout<<dp[n][m]<<"\n";
    for(int i=lg;i>0;i--) fout<<sol[i]<<" ";

}

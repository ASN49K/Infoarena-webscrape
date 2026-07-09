#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
short n,m,i,j,dp[1025][1025],a[1025],b[1025],s[1025],k,mx;
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++)
       {for(j=1;j<=m;j++) {if(a[i]==b[j]) dp[i][j]=1+dp[i-1][j-1];
                           else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);}}
    i=n;
    j=m;
    mx=dp[n][m];
    while (mx>0)
          {if(a[i]==b[j]) {s[++k]=a[i];
                           i--;
                           j--;
                           mx--;}
           else if(dp[i-1][j]==mx) i--;
           else j--;}
    fout<<dp[n][m]<<'\n';
    for (i=k;i>=1;i--)
         fout<<s[i]<<' ';
    return 0;
}

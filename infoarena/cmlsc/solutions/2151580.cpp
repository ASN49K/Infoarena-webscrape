#include <fstream>

using namespace std;

int n,m,i,j,t,p,poz;
int a[1025],b[1025],dp[1025][1025];

ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");

int main()
{
   fi>>n>>m;
   for(i=1;i<=n;i++)
    fi>>a[i];
   for(i=1;i<=m;i++)
    fi>>b[i];
   for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {if(a[i]==b[j])
        dp[i][j]=dp[i-1][j-1]+1;
    else
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//    for(t=1;t<=n;t++)
//        {for(p=1;p<=m;p++)
//        fo<<dp[t][p]<<" ";
//        fo<<endl;}
//    fo<<endl;
    }
    fo<<dp[n][m]<<'\n';
    for(i=1;i<=n;i++)
        for(j=poz+1;j<=m;j++)
        if(dp[i][j]!=dp[i-1][j] and dp[i][j]!=dp[i][j-1])
        {fo<<a[i]<<" ";
        poz=j;
        break;}
}

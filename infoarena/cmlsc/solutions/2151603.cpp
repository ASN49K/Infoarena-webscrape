#include <fstream>

using namespace std;

int n,m,i,j,t,p,l;
int a[1025],b[1025],dp[1025][1025],sol[1025];

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
    l=dp[n][m];
    fo<<dp[n][m]<<'\n';
    for(i=n;i>=1;i--)
        for(j=m;j>=1;j--)
        if(dp[i][j]==l and a[i]==b[j])
    {
        sol[l]=a[i];
        l--;
    }
    for(i=1;i<=dp[n][m];i++)
        fo<<sol[i]<<" ";
}

#include <fstream>
#include <algorithm>
#define maxn 1100

using namespace std;
int dp[maxn][maxn];
int a[maxn],b[maxn];
int sol[maxn];
int n,m;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

void read()
{
    in>>n>>m;
    for(int i=1;i<=n;i++)
    in>>a[i];
    for(int i=1;i<=m;i++)
    in>>b[i];
}

void dinamica()
{
    for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
      {
          if(a[i]==b[j])
            dp[i][j]=dp[i-1][j-1]+1;

         else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      }
}

void rec()
{

    for(int i=n,j=m;i;)
    {
        if(a[i]==b[j]) sol[++sol[0]]=a[i],i--,j--;
        else if(dp[i][j-1]>dp[i-1][j]) j--;
        else i--;
    }
}
int main()
{
    read();
    dinamica();
    rec();
    out<<dp[n][m]<<"\n";
    for(int i=dp[n][m];i>0;i--) out<<sol[i]<<" ";
    return 0;
}

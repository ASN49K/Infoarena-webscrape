#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int v1[1025], v2[1025], sol[1025], dp[1025][1025];
int n,m;

int main()
{
  f>>n>>m;

  for(int i=1;i<=n;i++)f>>v1[i];

  for(int i=1;i<=m;i++)f>>v2[i];

  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
      if(v1[i]==v2[j])
      {
        dp[i][j]=dp[i-1][j-1]+1;
      }
      else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
  }


   g<<dp[n][m]<<'\n';

   int i,j,k=0;
   i=n;
   j=m;

   while(i>0)
   {
      if(v1[i]==v2[j])
        sol[++k]=v1[i], i--, j--;
      else
      {
          if(dp[i-1][j]>dp[i][j-1]) i--;
          else j--;
      }
   }

   for(i=dp[n][m];i>=1;i--)g<<sol[i]<<' ';

   return 0;
}

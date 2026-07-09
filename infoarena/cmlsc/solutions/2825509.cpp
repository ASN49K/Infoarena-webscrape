//#include <iostream>
#include <fstream>

using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n,i,a[1030],dp[1030][1030],k,b[1030],nr,j,m,v[1030];
int main()
{
   cin>>n>>m;
   for(i=1;i<=n;i++)cin>>a[i];
   for(j=1;j<=m;j++)cin>>b[j];

   nr=0;
   k=0;
   for(i=1;i<=n;i++)
   for(j=1;j<=m;j++) dp[i][j]==0;

   for(i=1;i<=n;i++)
   {
       for(j=1;j<=m;j++)
       {
           if(a[i]==b[j]){nr++;
                          k++;
                          v[k]=b[j];}
           dp[i][j]=nr;
       }
   }

   cout<<dp[n][m]<<'\n';
   for(k=1;k<=nr;k++)cout<<v[k]<<" ";






    return 0;
}

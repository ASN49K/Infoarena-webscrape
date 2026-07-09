#include <iostream>
#include <fstream>
#define ll long long



using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int i,j,n,m,nrsol;
const ll nmax=1025;
int a[nmax],b[nmax],dp[nmax][nmax],sol[nmax];

int main()
{
    in>>n>>m;
    for(i=1;i<=n;i++)
        in>>a[i];
    for(j=1;j<=m;j++)
        in>>b[j];
    for(int i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i]==b[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
        }
   out<<dp[n][m]<<'\n';
   int i=n;j=m;
   while(i && j)
   {
       if(a[i]==b[j])
       {
           sol[++nrsol]=a[i];
           --i,--j;
       }
       else if(dp[i-1][j]>dp[i][j-1]){
          --i;} else
          {--j;}

   }
   while(nrsol)
    out<<sol[nrsol--];
   in.close();
   out.close();
    return 0;
}

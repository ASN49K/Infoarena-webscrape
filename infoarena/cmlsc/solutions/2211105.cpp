#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
const int MAX=1025;
int  a[MAX],na,b[MAX],nb,dp[MAX][MAX],sol[MAX];
int main()
{ in>>na>>nb;
for(int i=1;i<=na;i++)
    in>>a[i];
for(int i=1;i<=nb;i++)
    in>>b[i];
for(int i=1;i<=na;i++)
    for(int j=1;j<=nb;j++)
{   if(a[i]==b[j]) dp[i][j]=1+dp[i-1][j-1];

    else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
}
out<<dp[na][nb]<<endl;
while(dp[na][nb]>0)
{
    if(a[na]==b[nb])
    {
     sol[dp[x][y]] = a[x];
        --na;
        --nb;
    }
    else if(dp[na][nb]==dp[na-1][nb])
        --na;
    else --nb;
}
for(i=1;i<=dp[na][nb];i++)
        out<<sol[i]<<" ";
    return 0;
}

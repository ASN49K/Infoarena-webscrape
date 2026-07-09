#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
 int n,m,a[1030],b[1030],dp[1030][1030],sol[1030],nsol;
int main()
{ int i,j,i1,i2;
    f>>n>>m;
    for(i=1;i<=n;i++)
     f>>a[i];

    for(i=1;i<=m;i++)
     f>>b[i];

    for(i=1;i<=n;i++)
     for(j=1;j<=m;j++)
     {

       if (a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
       dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
     }


     i1=n; i2=m;

    for(;i1 && i2;)
    { if (a[i1]==b[i2] && dp[i1][i2]==dp[i1-1][i2-1]+1) {nsol++; sol[nsol]=a[i1];i1--; i2--; }
       else if (dp[i1][i2]==dp[i1-1][i2]) i1--;
        else i2--;

    }

    g<<nsol<<"\n";
    for(i=nsol;i>=1;i--)
     g<<sol[i]<<" ";
    return 0;
}

#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int dp[1025][1025],a[1025],b[1025],sol[1025];

int main()
{int n,m,i,j;
f>>n>>m;
for (i=1;i<=n;i++) f>>a[i];
for (i=1;i<=m;i++) f>>b[i];
for (i=1;i<=n;i++)
    for (j=1;j<=m;j++) if (a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
                                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
g<<dp[n][m]<<'\n';
int k=dp[n][m];
i=n;
j=m;
while (k>0 &&(i>0 || j>0)) {if (a[i]==b[j]) {sol[k]=a[i];
                                             i--;
                                             j--;
                                             k--;
                                            }
                                else if (dp[i][j]==dp[i-1][j]) i--;
                                         else j--;

                          }
for (i=1;i<=dp[n][m];i++) g<<sol[i]<<' ';
}

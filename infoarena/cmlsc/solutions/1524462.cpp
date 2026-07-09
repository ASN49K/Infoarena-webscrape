#include <stdio.h>
#define nmax 1030
using namespace std;
int n,m,i,j,x,t[nmax],v[nmax],dp[nmax][nmax],y[nmax];
inline int max(int a,int b) { if (a>b) return a; else return b; }
int main() {
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
scanf("%d %d",&n,&m);
for (i=1;i<=n;i++) scanf("%d",&t[i]);
for (i=1;i<=m;i++) scanf("%d",&v[i]);
for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
        if (t[i]==v[j]) dp[i][j]=dp[i-1][j-1]+1; else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
printf("%d\n",dp[n][m]); i=n; j=m;
while (dp[i][j]>0) {
    while (dp[i-1][j]==dp[i][j]) i--;
    while (dp[i][j-1]==dp[i][j]) j--;
    x++; y[x]=t[i];
    i--; j--;
}
for (i=x;i>=1;i--) printf("%d ",y[i]);
return 0;
}

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <time.h>
#include <bitset>
#include <string>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <limits.h>
#include <algorithm>
#include <deque>
#define inf 0x3f3f3f3f
#define mod 1000000007
#define nmax 100010
using namespace std;
int n,m,i,j,t[1030],v[1030],dp[1030][1030],sol[1030],nr;
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
         dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
i=n; j=m;
while (dp[i][j]) {
    while (dp[i][j]==dp[i][j-1]) j--;
    while (dp[i][j]==dp[i-1][j]) i--;
    nr++; sol[nr]=t[i];
    i--; j--;
}
printf("%d\n",nr);
for (i=1;i<=nr;i++) printf("%d ",sol[nr-i+1]);
return 0;
}

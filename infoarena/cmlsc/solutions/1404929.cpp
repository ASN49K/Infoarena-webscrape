#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,a[1030],b[1030],dp[1030][1030],v[1030];
int main(){
    int i,j;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++)
     scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
     scanf("%d",&b[i]);
    for(i = 1; i <= m; i++)
     for(j = 1; j <= n; j++)
     {
         if(a[i] == b[j])
          dp[i][j] = dp[i-1][j-1] + 1;
         else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
     }
     printf("%d\n",dp[m][n]);
      int l=dp[m][n];
  i=m;
  j=n;
  for(l;l;){
    if(a[i]==b[j]){
      v[l]= a[i];
      l--;
      i--;
      j--;
    }
    else if(dp[i-1][j]>dp[i][j-1])  i--;
      else j--;
  }
       for(i=1;i<=dp[m][n];++i)
        printf("%d ",v[i]);
    printf("\n");
    return 0;
}

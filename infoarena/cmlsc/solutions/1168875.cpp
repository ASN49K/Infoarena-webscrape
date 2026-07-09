#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,a[1030],b[1030],dp[1030][1030],v[1030];
int main(){
    int i,j,k,c;
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
     k = dp[m][n];
     c=1;
     for(i = m; i >= 1;)
      for(j = n; j >= 1;)
       if(a[i] == b[j])
       {
           k--;
           v[c++] = b[j];
           i--;
           j--;
       }
        else if (dp[i-1][j] < dp[i][j-1])
            j--;
        else
            i--;

       for(i=c-1;i>0;--i)
        printf("%d ",v[i]);
    printf("\n");
//     for(i = 1; i <= m; i++)
//      {
//          for(j = 1; j<=n;j++)
//           cout << dp[i][j]<<" ";
//        cout <<"\n";
//      }
    return 0;
}

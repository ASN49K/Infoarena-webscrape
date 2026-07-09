#include <bits/stdc++.h>
using namespace std;
#define input "cmlsc.in"
#define output "cmlsc.out"
#define Nmax 1013

int n,m;
int a[Nmax],b[Nmax];
int dp[Nmax][Nmax];
vector <int> v;

int main(void){
   freopen(input,"r",stdin);
   freopen(output,"w",stdout);
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;++i) scanf("%d",a+i);
   for (int i=1;i<=m;++i) scanf("%d",b+i);

   dp[0][0]=0;
   for (int i=1;i<=n;++i)
      for (int j=1;j<=m;++j)
        dp[i][j] = (a[i]==b[j]) ? dp[i-1][j-1]+1 : max(dp[i-1][j],dp[i][j-1]);

  printf("%d\n",dp[n][m]);

  for (int i=n,j=m;i>=1 || j>=1;)
     if (a[i]==b[j]) v.push_back(a[i]), --i, --j;
              else {
                if (dp[i-1][j] > dp[i][j-1]) --i;
                           else --j;
              }

 for (int i=v.size()-1;i>=0;--i)
   printf("%d ",v[i]);
return 0;
}

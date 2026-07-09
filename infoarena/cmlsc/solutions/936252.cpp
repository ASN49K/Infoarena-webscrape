#include <fstream>
#define LE 1066
using namespace std;
ifstream f("cmlsc.in");ofstream g("cmlsc.out");
int i,j,n,m,a[LE],b[LE],dp[LE][LE],result[LE],k;

int main(){
    f>>n>>m;
    for(i=1;i<=n;++i) f>>a[i];
    for(j=1;j<=m;++j) f>>b[j];

    for(i=1;i<=n;++i)
       for(j=1;j<=m;++j)
         if (a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
         else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);


    for(i=n,j=m;i>0&&j>0;)
      if (a[i]==b[j]) result[++k]=a[i],--i,--j;
      else{
        if (dp[i-1][j]>dp[i][j-1]) i--; else --j;
      }

    g<<k<<'\n';
    for(i=k;i>=1;--i) g<<result[i]<<" ";

    g<<'\n';
f.close();g.close();
    return 0;
}

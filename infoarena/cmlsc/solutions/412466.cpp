#include <stdio.h>
#define max(a,b) ((a>b)?a:b)
const int N=1024;
int c[N][N];

int main(){
  freopen("cmlsc.in","r",stdin); freopen("cmlsc.out","w",stdout);
  int n,m,i,j,q,a[N],b[N],sol[N];

  scanf("%d %d",&n,&m);
  for (i=1;i<=n;++i)scanf("%d",&a[i]);
  for (i=1;i<=m;++i)scanf("%d",&b[i]);
  
  for (i=1;i<=n;++i)
    for (j=1;j<=m;++j)
      if (a[i]==b[j]) c[i][j] = c[i-1][j-1] + 1;
      else c[i][j] = max( c[i-1][j], c[i][j-1] );

  printf("%d\n",c[n][m]);
  //print one of the substrings
  q=c[n][m];
  for(i=n,j=n;i&&j;)
    if (a[i]==b[j]){sol[q--]=a[i];i--;j--;}
    else if (c[i-1][j]>c[i][j-1])i--; else j--;
  q=c[n][m];
  for (i=1;i<=q;++i)printf("%d ",sol[i]);
  
return 0;
}

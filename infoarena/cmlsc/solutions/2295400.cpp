#include <cstdio>
#include <algorithm>
#define MAXN 1024
using namespace std;

int c[MAXN][MAXN];
int dir[MAXN][MAXN];
int x[MAXN], y[MAXN];

int reconstituire( int i, int j ) {
  if( i == 0 || j == 0 )
    return 0;
  if( dir[i][j] == 2 ) {
     reconstituire(i-1,j-1);
      printf("%d ",x[i]);
  }
  else if( dir[i][j] == 1 )
    reconstituire(i-1,j);
  else
    reconstituire(i,j-1);
}

int main() {
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int a,k,i,j,n,m;
    scanf("%d%d",&n,&m);
    for( i = 1; i <= n; i ++ )
      scanf("%d",&x[i]);
    for( j = 1; j <= m; j ++ )
      scanf("%d",&y[j]);
    for( i = 1; i <= n; i ++ )
      for( j = 1; j <= m; j ++ ) {
         if( x[i] == y[j])
           c[i][j] = c[i-1][j-1] + 1, dir[i][j] = 2;
         else {
           c[i][j] = max( c[i-1][j], c[i][j-1] );
           if( c[i-1][j] > c[i][j-1] )
              dir[i][j] = 1;
           else
              dir[i][j] = -1;
         }
      }
    printf("%d\n",c[n][m]);
    reconstituire(n,m);
    return 0;
}

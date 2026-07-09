#include<cstdio>
#include<cstring>

void lcs( int a[], int n, int b[], int m ){
  int i,j;
  int M[n+1][m+1];
  char P[n+1][m+1];
  
  for( i=0; i<=n; ++i ){
    for( j=0; j<=m; ++j ){
      M[i][j] = 0;
      P[i][j] = 'x';
    }
  }
  
  for( i=1; i<=n; ++i ){
    for( j=1; j<=m; ++j ){
      if( a[i-1] == b[j-1] ){
        M[i][j] = M[i-1][j-1] + 1;
        P[i][j] = '\\';
      } else {
        if( M[i-1][j] > M[i][j-1] ){
          M[i][j] = M[i-1][j];
          P[i][j] = '|';
        } else {
          M[i][j] = M[i][j-1];
          P[i][j] = '-';
        }
      }
    }
  }
  
  int max = M[n][m]-1;
  int R[max];
  for( i=n,j=m; max>=0; ){
    switch( P[i][j] ){
      case '\\':
        R[max] = a[i-1];
        --max;
        --j;
        --i;
        break;
      case '-':
        --j;
        break;
      case '|':
        --i;
        break;
      default: case 'x':
        max = -1;
        break;
    }
  }
  
  printf("%d\n", M[n][m]);
  for( i=0; i<M[n][m]; ++i ){
    printf("%d ", R[i]);
  }
  
}

int main(){
  
  int n,m,i;
  
  freopen( "cmlsc.in", "r", stdin );
  freopen( "cmlsc.out", "w", stdout );
  
  scanf( "%d %d", &n, &m );
  int a[n], b[m];
  
  for( i=0; i<n; ++i ){
    scanf("%d", &a[i] );
  }
  for( i=0; i<m; ++i ){
    scanf("%d", &b[i] );
  }
  
  lcs( a, n, b, m );
  
  return 0;
  
}

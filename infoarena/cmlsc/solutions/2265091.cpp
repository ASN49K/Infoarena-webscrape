#include <cstdio>

#define MAXL 1025

using namespace std;

int dp[MAXL+5][MAXL+5];
int a[MAXL+5], b[MAXL+5];

inline int maxim( int a, int b, int c )
{
  if( a<b )
    a=b;

  if( a<c )
    a=c;

  return a;
}

int main()
{
  freopen( "cmlsc.in", "r", stdin );
  freopen( "cmlsc.out", "w", stdout );

  int n, m;

  scanf( "%d%d", &n, &m );

  for( int i=1;i<=n;i++ )
    scanf( "%d", &a[i] );

  for( int i=1;i<=m;i++ )
    scanf( "%d", &b[i] );

  for( int i=1;i<=n;i++ )
    for( int j=1;j<=m;j++ )
      dp[i][j]=maxim(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]+(a[i]==b[j]));

  printf( "%d\n", dp[n][m] );

  int p=1;

  for( int i=1;i<=n && p<=dp[n][m];i++ )
    for( int j=1;j<=m && p<=dp[n][m];j++ )
      if( dp[i][j]==p && a[i]==b[j] )
      {
        printf( "%d ", a[i] );
        p++;
      }

  return 0;
}

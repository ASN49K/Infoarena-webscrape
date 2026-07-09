#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

int max(int a, int b) {
	return a > b ? a : b;
}

int main()
{
  int m, n, a[MAX+1], b[MAX+1];
  scanf("%d %d", &m, &n);
  int i, j;
  for ( i = 1; i <= m; i++ )
    scanf("%d",&a[i]);
  for ( j = 1; j <= n; j++ )
  	scanf("%d",&b[j]);

  char c[MAX+1][MAX+1];
  for ( i = 0; i <= m; i++ )
  	c[i][0] = 0;
  for ( j = 0; j <= n; j++)
  	c[0][j] = 0;
  for ( i = 1; i <= m; i++ )
  	for ( j = 1; j <= n; j++)
  		if ( a[i] == b[j] )
  			c[i][j] = c[i-1][j-1]+1;
  		else
  			c[i][j] = max( c[i][j-1], c[i-1][j] );

  printf("%d", c[m][n]);

  return 0;
}

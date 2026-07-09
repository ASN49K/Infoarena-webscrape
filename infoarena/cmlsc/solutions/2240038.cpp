#include <iostream>
#include <stdio.h>
#include <algorithm>

#define NMAX 1024

using namespace std;

int v1 [ NMAX ] ;
int v2 [ NMAX ] ;
int mat [NMAX] [NMAX] ;
int sol [ NMAX ] ;
int main() {

  FILE *fin, *fout ;
  fin = fopen ("cmlsc.in", "r" ) ;
  fout = fopen ("cmlsc.out", "w" ) ;
  int n, i, m, j, i2, maxim, count, p1, p2 ;
  fscanf (fin, "%d%d", &n, &m ) ;
  for (i = 1; i <= n ; i++ )
    fscanf (fin, "%d", &v1[i] ) ;
  for (i = 1; i <= m ; i++ )
    fscanf (fin, "%d", &v2[i] ) ;
  for (i = 1 ; i <= n ; i++ )
    for (j = 1 ; j <= m ; j++ )
      if (v1[i] == v2[j] )
        mat[i][j] = mat[i-1][j-1] + 1 ;
      else
        mat[i][j] = max (mat[i-1][j], mat[i][j-1] ) ;
  p1 = p2 = 0 ;
  maxim = 0 ;
  for (i = 1 ; i <= n ; i++ )
    for (j = 1 ; j <= m ; j++ )
      if (mat[i][j] > maxim ) {
        p1 = i ;
        p2 = j ;
        maxim = mat[i][j] ;
      }
  count = NMAX-1 ;
  while (p1 > 0 && p2 > 0 ) {
    if (v1[p1] == v2[p2] ) {
      sol[count--] = v1[p1] ;
      p1--;
      p2--;
    }
    else {
      if (mat[p1][p2] == mat[p1-1][p2] )
        p1--;
      else if (mat[p1][p2] == mat[p1][p2-1])
        p2--;
    }
  }
  fprintf (fout, "%d\n", maxim ) ;
  for (i = count+1 ; i < NMAX ; i++ )
    fprintf (fout, "%d ", sol[i] ) ;
  return 0;
}

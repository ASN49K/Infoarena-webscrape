#include <iostream>
#include <stdio.h>

#define NMAX 1024

using namespace std;

int v1 [ NMAX ] ;
int v2 [ NMAX ] ;
int l [ NMAX ] ;

int main() {

  FILE *fin, *fout ;
  fin = fopen ("cmlsc.in", "r" ) ;
  fout = fopen ("cmlsc.out", "w" ) ;
  int n, i, m, j, i2, maxim, count ;
  fscanf (fin, "%d%d", &n, &m ) ;
  for (i = 1; i <= n ; i++ )
    fscanf (fin, "%d", &v1[i] ) ;
  for (i = 1; i <= m ; i++ )
    fscanf (fin, "%d", &v2[i] ) ;
  for (j = 1 ; j <= m ; j++ ) {
    i = n ;
    maxim = 0 ;
    while (v1[i] != v2[j] && i > 0 )
      i--;
    i2 = i ;
    while (i > 0 ) {
      if (l[i] > maxim )
        maxim = l[i] ;
      i--;
    }
    l[i2] = maxim+1;
  }
  maxim = 0 ;
  for (i = 1 ; i <= n ; i++ )
    if (l[i] > maxim )
        maxim = l[i] ;
  fprintf (fout, "%d\n", maxim ) ;
  count = 1 ;
  for (i = 1 ; i <= n ; i++ )
    if (l[i] == count ) {
      count++;
      fprintf (fout, "%d ", v1[i] ) ;
    }
  return 0;
}

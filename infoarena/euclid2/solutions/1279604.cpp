#include <stdio.h>
#include <stdlib.h>
 
int euclid(unsigned int a, unsigned int b) {
  if ( b == 0 )
    return a;
  return euclid(b, a%b);
}
 
int main()
{
  FILE *in  = fopen("euclid2.in","r");
  FILE *out = fopen("euclid2.out","w");
 
  int n;
  fscanf(in,"%ud",&n);
 
  int i, a, b;
  for ( i = 1; i <= n; i++ ) {
    fscanf( in,"%d %d", &a, &b);
    fprintf( out, "%d\n", euclid(a,b) );
  }
 
  fclose(in);
  fclose(out);
 
  return 0;
}

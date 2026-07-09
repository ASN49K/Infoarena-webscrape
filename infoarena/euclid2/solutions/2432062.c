#include <stdio.h>

int main()
{
  FILE *fin, *fout;
  fin = fopen( "euclid2.in", "r" );
  fout = fopen( "euclid2.out", "w" );
  int a, b, cmmdc, i, n;
  fscanf( fin, "%d", &n );
  for ( i = 0; i < n; i++ ){
    fscanf( fin, "%d%d", &a, &b );
    while (b != 0)
    {
        cmmdc = b;
        b = a % b;
        a = cmmdc;
    }
    fprintf( fout, "%d\n", cmmdc );
  }
  fclose( fin );
  fclose( fout );
  return 0;
}

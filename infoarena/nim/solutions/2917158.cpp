// This program was written by Mircea Rebengiuc
// on 03.08.2022
// for problem nim

#include <stdio.h>
#include <ctype.h>

FILE *fin, *fout;

static inline int fgetint(){
  int n = 0, ch;

  while( !isdigit( ch = fgetc( fin ) ) );
  do
    n = n * 10 + ch - '0';
  while( isdigit( ch = fgetc( fin ) ) );

  return n;
}

int solve_testcase(){
  int n = fgetint(), ret = 0;

  for( ; n-- ; ) ret ^= fgetint();

  return !!ret;
}

int main(){
  fin = fopen( "nim.in", "r" );
  fout = fopen( "nim.out", "w" );

  for( int t = fgetint() ; t-- ; )
    fputs( solve_testcase() ? "DA\n" : "NU\n", fout );

  fclose( fout );
  fclose( fin );
  return 0;
}
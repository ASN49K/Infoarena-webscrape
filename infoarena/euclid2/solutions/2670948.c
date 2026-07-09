#include <stdio.h>
#include <ctype.h>

FILE *fin, *fout;

static inline int fgetint(){
  int n = 0, ch;

  while( !isdigit(ch = fgetc(fin)) );
  do
    n = n * 10 + ch - '0';
  while( isdigit(ch = fgetc(fin)) );

  return n;
}

static inline void fputint( int n ){
  int p10 = 1000000000;

  while( p10 > n )
    p10 /= 10;

  while( p10 > 0 ){
    fputc('0' + (n / p10) % 10, fout);
    p10 /= 10;
  }
  
  fputc('\n', fout);
}

int cmmdc( int a, int b ){
  if( b == 0 )
    return a;

  return cmmdc(b, a % b);
}

int main(){
  fin  = fopen("euclid2.in",  "r");
  fout = fopen("euclid2.out", "w");
  
  int t;

  for( t = fgetint() ; t-- ; )
    fputint(cmmdc(fgetint(), fgetint()));

  fclose(fin);
  fclose(fout);
  return 0;
}

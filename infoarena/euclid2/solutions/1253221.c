// Educational 01: Euclid
#include <stdio.h>

#define MAX(a,b) (a > b ? a : b)
#define MIN(a,b) (a < b ? a : b)

long int euclid(long int a, long int b) {
  long int x;
  while(a != b) {
    if(a < b) { x = a; a = b; b = x;  }
    a -= b;
  }
  return b;
}

int main() {
  long int n, i, a, b, x;

  FILE *in = fopen("euclid2.in", "r");
  FILE *out = fopen("euclid2.out", "w");

  fscanf(in, "%ld", &n);

  for(i=0; i<n; i++) {
    fscanf(in, "%ld %ld", &a, &b);
    fprintf(out, "%ld\n", euclid(a, b));
  }

  fclose(out);
}


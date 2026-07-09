#include <stdio.h>

int main() {
  FILE *fi, *fo;
  long a,b,r,i,n;
  fi = fopen("euclid2.in", "r");
  fo = fopen("euclid2.out", "w");
  fscanf(fi, "%ld", &n);
  for (i = 0; i < n; i++) {
    fscanf(fi, "%ld", &a);
    fscanf(fi, "%ld", &b);
    do {
      r = a % b;
      a = b;
      b = r;
    } while (r != 0);
    fprintf(fo, "%ld\n", a);
  }
  fclose(fi);
  fclose(fo);
  return 0;
}
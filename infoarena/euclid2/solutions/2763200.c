#include <stdio.h>

int cmmdc(int a, int b) {
  int c;
  c = a % b;
  while (c != 0) {
    a = b;
    b = c;
    c = a % b;
  }
  return b;
}

int main() {
  int n, a, b, i, max = 1, ret;
  FILE *f_in, *f_out;
  f_in = fopen("euclid2.in", "r");
  f_out = fopen("euclid2.out", "w");
  fscanf(f_in, "%d", &n);
  printf("%d", n);
  for (i = 0; i < n; i++) {
    fscanf(f_in, "%d %d", &a, &b);
    fprintf(f_out, "%d\n", cmmdc(a, b));
  }

  fclose(f_in);
  fclose(f_out);
  return 0;
}

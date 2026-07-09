#include <stdio.h>

int main() {
  int n, a, b, c, i;
  FILE *f_in, *f_out;
  f_in = fopen("euclid2.in", "r");
  f_out = fopen("euclid2.out", "w");
  fscanf(f_in, "%d", &n);
  for (i = 0; i < n; i++) {
    fscanf(f_in, "%d %d", &a, &b);
    c = a % b;
    while (c != 0) {
      a = b;
      b = c;
      c = a % b;
    }
    fprintf(f_out, "%d\n", b);
  }
}

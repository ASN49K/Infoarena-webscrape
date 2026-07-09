#include <stdio.h>

int main() {
  FILE *fin, *fout;
  fin = fopen("euclid2.in", "r");
  fout = fopen("euclid2.out", "w");
  int a, b, i, n, cmmdc, ca, cb, r;
  fscanf(fin, "%d", &n);
  for (i = 1; i <= n; i++) {
    fscanf(fin, "%d%d", &a, &b);
    ca = a;
    cb = b;
    while (cb) {
      r = ca % cb;
      ca = cb;
      cb = r;
    }
    fprintf(fout, "%d\n", ca);
  }
  return 0;
}

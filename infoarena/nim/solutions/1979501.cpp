#include <cstdio>

int main() {
  FILE *fin, *fout;
  int t, n, s, x;
  fin = fopen("nim.in", "r");
  fscanf(fin, "%d", &t);
  fout = fopen("nim.out", "w");
  for (int i = 0; i < t; ++i) {
    fscanf(fin, "%d", &n);
    s = 0;
    for (; n > 0; --n) {
      fscanf(fin, "%d", &x);
      s ^= x;
    }
    if (!s) {
      fprintf(fout, "NU\n");
    } else {
      fprintf(fout, "DA\n");
    }
  }
  fclose(fin);
  fclose(fout);
  return 0;
}

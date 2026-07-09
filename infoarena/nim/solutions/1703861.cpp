#include <cstdio>
int main() {
  int t, n, i, j, s, x;
  FILE *fin = fopen("nim.in", "r");
  FILE *fout = fopen("nim.out", "w");
  fscanf(fin, "%d", &t);
  for(i = 0; i < t; i++) {
    fscanf(fin, "%d", &n);
    s = 0;
    for(j = 0; j < n; j++) {
      fscanf(fin, "%d", &x);
      s = s ^ x;
    }
    if(s == 0)
      fprintf(fout, "NU\n");
    else
      fprintf(fout, "DA\n");
  }
  fclose(fin);
  fclose(fout);
  return 0;
}

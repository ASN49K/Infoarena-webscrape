#include <stdio.h>

int v1[1025];
int v2[1025];

int mat[1025][1025];

static inline int max(int a, int b) { return a > b ? a : b; }

int main() {
  FILE *fin, *fout;
  int n, m;
  int i, j;

  fin = fopen("cmlsc.in", "r");

  fscanf(fin, "%d", &n);
  fscanf(fin, "%d", &m);
  for (i = 1; i <= n; i++)
    fscanf(fin, "%d", &v1[i]);
  for (i = 1; i <= m; i++)
    fscanf(fin, "%d", &v2[i]);

  fclose(fin);

  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (v1[i] == v2[j])
        mat[i][j] = mat[i - 1][j - 1] + 1;
      else
        mat[i][j] = max(mat[i][j - 1], mat[i - 1][j]);
    }
  }

  fout = fopen("cmlsc.out", "w");

  i = n;
  j = m;
  fprintf(fout, "%d\n", mat[i][j]);
  while (i >= 1 && j >= 1) {
    if (v1[i] == v2[j]) {
      fprintf(fout, "%d ", v1[i]);
      i--; j--;
    } else {
      if (mat[i - 1][j] > mat[i][j - 1])
        i--;
      else
        j--;
    }
  }

  fclose(fout);

  return 0;
}

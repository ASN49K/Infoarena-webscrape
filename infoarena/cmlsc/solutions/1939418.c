#include <stdio.h>

#define MAXN 1024

int a[MAXN], b[MAXN], L[MAXN][MAXN], ans[MAXN];

int max(int a, int b) {
  return a > b ? a : b;
}

int main(void) {
  int res, n, m;
  FILE *f = fopen("cmlsc.in", "r");
  fscanf(f, "%d%d", &n, &m);
  int i = 1;
  for (; i <= n; ++i) {
    fscanf(f, "%d", &a[i]);
  }
  int j = 1;
  for (; j <= m; ++j) {
    fscanf(f, "%d", &b[j]);
  }
  fclose(f);
  for (i = 1; i <= n; ++i) {
    for (j = 1; j <= m; ++j) {
      if (a[i] == b[j]) {
        L[i][j] = L[i - 1][j - 1] + 1;
      } else {
        L[i][j] = max(L[i - 1][j], L[i][j - 1]);
      }
    }
  }
  res = 0;
  i = n;
  j = m;
  for (; i;) {
    if (a[i] == b[j]) {
      ans[++res] = a[i];
      --i;
      --j;
    } else if (L[i - 1][j] < L[i][j - 1]) {
      --j;
    } else {
      --i;
    }
  }
  f = fopen("cmlsc.out", "w");
  fprintf(f, "%d\n", res);
  for (i = res; i; i--) {
    fprintf(f, "%d ", ans[i]);
  }
  fprintf(f, "\n");
  fclose(f);
  return 0;
}

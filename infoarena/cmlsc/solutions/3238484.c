	
#include <stdio.h>
 
#define NMAX 1024
 
short a[NMAX + 1], b[NMAX + 1], len[NMAX + 1][NMAX + 1], afis[NMAX];
 
static inline int max(int a, int b) {
  return a > b ? a : b;
}
 
int main() {
  FILE *fin, *fout;
  int n, m, i, j, p;
  fin = fopen("cmlsc.in", "r");
  fscanf(fin, "%d%d ", &n, &m);
  for (i = 1; i <= n; i++)
    fscanf(fin, "%hd", &a[i]);
  for (i = 1; i <= m; i++)
    fscanf(fin, "%hd", &b[i]);
  fclose(fin);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (a[i] == b[j])
        len[i][j] = 1 + len[i - 1][j - 1];
      else
        len[i][j] = max(len[i - 1][j], len[i][j - 1]);
  fout = fopen("cmlsc.out", "w");
  fprintf(fout, "%d\n", len[i = n][j = m]);
  p = 0;
  while (i > 0 && j > 0)
    if (a[i] == b[j]) {
      afis[p++] = a[i--];
      j--;
    } else if (len[i][j] == len[i - 1][j])
      i--;
    else
      j--;
  while (p > 0)
    fprintf(fout, "%d ", afis[--p]);
  fputc('\n', fout);
  fclose(fout);
  return 0;
}
#include <iostream>
#include <stdio.h>
#define NMAX 1024
#define MMAX 1024

using namespace std;

int v1[NMAX + 1], v2[MMAX + 1], dp[NMAX + 1][MMAX + 1], sol[NMAX + 1];

int maxim(int a, int b) {
  return a < b ? b : a;
}

int main() {
  FILE *fin, *fout;
  int n, m, nsol, i, j, lcur;

  fin = fopen("cmlsc.in", "r");
  fscanf(fin, "%d%d", &n, &m);

  for (i = 1; i <= n; i++)
    fscanf(fin, "%d", &v1[i]);
  for (i = 1; i <= m; i++)
    fscanf(fin, "%d", &v2[i]);
  fclose( fin );

  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (v1[i] == v2[j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = maxim(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  nsol = 0;
  lcur = dp[n][m];
  i = n;
  j = m;
  while (lcur > 0) {
    if (dp[i - 1][j] == lcur)
      i--;
    else if (dp[i][j - 1] == lcur)
      j--;
    else {
      sol[nsol++] = v1[i];
      i--;
      j--;
      lcur--;
    }
  }

  fout = fopen("cmlsc.out", "w");
  fprintf(fout, "%d\n", nsol);
  for (i = nsol - 1; i >= 0; i--)
    fprintf(fout, "%d ", sol[i]);
  fclose( fout );
  return 0;
}

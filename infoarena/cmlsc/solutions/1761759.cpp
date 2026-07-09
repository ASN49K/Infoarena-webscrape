#include <cstdio>
#include <cmath>

#define NMAX 1030
#define max(a, b) (a > b ? a : b)

int D[NMAX][NMAX], n, m, a[NMAX], b[NMAX], sol[NMAX];

int main() {
  freopen("cmlsc.in", "r", stdin);
  freopen("cmlsc.out", "w", stdout);
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &b[i]);
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i] == b[j]) {
        D[i][j] = D[i-1][j-1] + 1;
      } else {
        D[i][j] = max(D[i-1][j], D[i][j-1]);
      }
    }
  }

  int i = n;
  int j = m;
  int k = D[n][m];

  while(k > 0) {
    if (a[i] == b[j]) {
      sol[k] = a[i];
      i--;
      j--;
      k--;
    } else if (D[i-1][j] > D[i][j-1]) {
      i--;
    } else {
      j--;
    }
  }
  printf("%d\n", D[n][m]);
  for (int i = 1; i <= D[n][m]; i++) {
    printf("%d ", sol[i]);
  }
  return 0;
}

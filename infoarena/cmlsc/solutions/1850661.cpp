#include <bits/stdc++.h>

using namespace std;

const int N = 1111;
const int INF = 0x3f3f3f3f;

int a[N], b[N];
int dp[N][N];
int d[N][N];

void print_lcs(int i, int j) {
  if (i == 0 || j == 0) {
    return;
  }
  if (d[i][j] == 1) {
    print_lcs(i - 1, j - 1);
    printf("%d ", a[i]);
  } else if (d[i][j] == 2) {
    print_lcs(i - 1, j);
  } else {
    print_lcs(i, j - 1);
  }
}

int main() {
  freopen("cmlsc.in", "r", stdin);
  freopen("cmlsc.out", "w", stdout);
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", b + i);
  }
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }
  for (int i = 0; i <= m; i++) {
    dp[0][i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i] == b[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        d[i][j] = 1;
      } else {
        if (dp[i - 1][j] >= dp[i][j - 1]) {
          dp[i][j] = dp[i - 1][j];
          d[i][j] = 2;
        } else {
          dp[i][j] = dp[i][j - 1];
          d[i][j] = 0;
        }
      }
    }
  }
  printf("%d\n", dp[n][m]);
  print_lcs(n, m);
  puts("");
  fflush(stdout);
  return 0;
}

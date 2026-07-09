/**
  *  Worg
  */
#include <cstdio>
#include <algorithm>

FILE *fin = freopen("cmlsc.in", "r", stdin); FILE *fout = freopen("cmlsc.out", "w", stdout);

const int maxN = 1024 + 5;

/*-------- Data --------*/
int n, m;
int a[maxN], b[maxN];

int dp[maxN][maxN];
int substr[maxN];
/*-------- --------*/

void ReadInput() {
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for(int i = 1; i <= m; i++) {
    scanf("%d", &b[i]);
  }
}

void LongestCommonSubstring() {
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(a[i] == b[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  //  Print result
  printf("%d\n", dp[n][m]);

  int x = n, y = m, cursor = 0;

  while(x > 0 && y > 0) {
    if(a[x] == b[y]) {
      substr[cursor++] = a[x];
      x--; y--;
    } else if(dp[x - 1][y] > dp[x][y - 1]) {
      x--;
    } else {
      y--;
    }
  }

  for(int i = cursor - 1; i >= 0; i--) {
    printf("%d ", substr[i]);
  }
}

int main() {
  ReadInput();

  LongestCommonSubstring();

  return 0;
}

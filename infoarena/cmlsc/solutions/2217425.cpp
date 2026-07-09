#include <stdio.h>
#define N 1025
#define max(A, B) A > B ? (A) : (B)

int A[N], B[N];
int dp[N][N];

void print(int m, int n) {
  if (dp[m][n]) {
    if (dp[m - 1][n] > dp[m][n - 1])
      print(m - 1, n);
    else
      print(m, n - 1);
    if (A[m] == B[n])
      printf("%d ", A[m]);
  }
}

int main(void) {
  freopen("cmlsc.in", "r", stdin);
  freopen("cmlsc.out", "w", stdout);

  int n_size;
  int m_size;
  scanf("%d", &m_size);
  scanf("%d", &n_size);
  for (int i = 1; i <= m_size; ++i)
    scanf("%d", &A[i]);

  for (int i = 1; i <= n_size; ++i)
    scanf("%d", &B[i]);

  for (int i = 1; i <= m_size; ++i)
    for (int j = 1; j <= n_size; ++j) {
      if (A[i] == B[j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  print(m_size, n_size);

}

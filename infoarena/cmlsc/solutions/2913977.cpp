#include <fstream>
#include <stdio.h>
#define NMAX 1024
#define MMAX 1024

using namespace std;

int v1[NMAX + 1], v2[MMAX + 1], dp[NMAX + 1][MMAX + 1], vsol[NMAX + 1];

ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");

int main() {
  int n, m, i, j, nsol;
  cin >> n >> m;

  for (i = 1; i <= n; i++)
    cin >> v1[i];
  for (i = 1; i <= m; i++)
    cin >> v2[i];

  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (v1[i] == v2[j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  i = n;
  j = m;
  nsol = 0;
  while (i >= 1 && j >= 1) {
    if (v1[i] == v2[j]) {
      vsol[nsol++] = v1[i];
      i--;
      j--;
    }
    else if (dp[i][j - 1] > dp[i - 1][j])
      j--;
    else
      i--;
  }

  cout << dp[n][m] << "\n";
  for (i = nsol - 1; i >= 0; i--)
    cout << vsol[i] << " ";
  return 0;
}

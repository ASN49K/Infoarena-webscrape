#include <cstdio>
#include <vector>

using namespace std;

const int NMAX = 1024;

int N[NMAX + 5], M[NMAX + 5];
int dp[NMAX + 5][NMAX + 5];  /// dp[i][j] = cmlsc folosind i caractere din N si j caractere din M
vector<int>sol;

inline int myMax(int a, int b) {
  return a > b ? a : b;
}

void add(int val) {
  sol.push_back(val);
}

void nextPosition(int &i, int &j) {
  if (N[i] == M[j]) {
    add(N[i]);
    i--;
    j--;
  } else {
    if (dp[i][j] == dp[i - 1][j])
      i--;
    else
      j--;
  }
}

int main() {
  freopen("cmlsc.in", "r", stdin);
  freopen("cmlsc.out", "w", stdout);

  int n, m;

  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &N[i]);
  for (int i = 1; i <= m; ++i)
    scanf("%d", &M[i]);

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (N[i] == M[j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = myMax(dp[i - 1][j], dp[i][j - 1]);

  for (int i = n, j = m; i != 0 && j != 0; nextPosition(i, j));

  printf("%d\n", dp[n][m]);

  for (int afis = sol.size() - 1; afis >= 0; --afis)
    printf("%d ", sol[afis]);

  return 0;
}

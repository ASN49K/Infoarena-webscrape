#include <cstdio>
#include <list>

int x[2 + 1024], y[2 + 1024], lcs[2 + 1024][2 + 1024];

int main() {
  freopen("cmlsc.in", "r", stdin);
  freopen("cmlsc.out", "w", stdout);
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    scanf("%d", &x[i]);
  for (int i = 1; i <= m; i++)
    scanf("%d", &y[i]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (x[i] == y[j])
        lcs[i][j] = 1 + lcs[i - 1][j - 1];
      else
        lcs[i][j] = std::max(lcs[i - 1][j], lcs[i][j - 1]);
  int i = n, j = m;
  std::list<int> sol;
  while(i > 0 && j > 0) {
    if (x[i] == y[j]) {
      sol.push_front(x[i]);
      i--;
      j--;
    } else {
      if (lcs[i - 1][j] > lcs[i][j - 1])
        i--;
      else
        j--;
    }
  }
  printf("%d\n", sol.size());
  for (int i : sol)
    printf("%d ", i);
  return 0;
}

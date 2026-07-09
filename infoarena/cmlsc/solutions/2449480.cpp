#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1025;
int n, m;
int a[N];
int b[N];
int l[N][N];
int match[N], cur;

int main() {
  freopen ("cmlsc.in", "r", stdin);
  freopen ("cmlsc.out", "w", stdout);

  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]);
  for (int i = 1; i <= m; i++)
    scanf("%d", &b[i]);

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i] == b[j])
        l[i][j] = 1 + l[i - 1][j - 1];
      else
        l[i][j] = max(l[i - 1][j], l[i][j - 1]);

  int i = n, j = m;
  while (i && j) {
    if (a[i] == b[j]) {
      match[++cur] = a[i];
      i--;
      j--;
    } else if (l[i - 1][j] > l[i][j - 1])
      i--;
    else
      j--;
  }

  printf("%d\n", cur);
  for (int i = cur; i >= 1; i--)
    printf("%d ", match[i]);
  printf("\n");

  return 0;
}

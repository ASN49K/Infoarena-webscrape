#include <stdio.h>

int main() {

  freopen("nim.in", "r", stdin);
  freopen("nim.out", "w", stdout);

  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    int n;
    scanf("%d", &n);
    int val = 0;
    for (int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      val ^= x;
    }
    if (val != 0)
      printf("DA\n");
    else
      printf("NU\n");
  }

  return 0;
}

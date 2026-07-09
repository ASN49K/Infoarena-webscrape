#include <bits/stdc++.h>

int main() {
  freopen("euclid2.in", "r", stdin);
  freopen("euclid2.out", "w", stdout);
  int n, a, b, r;
  scanf("%d", &n);
  while (n --) {
    scanf("%d %d", &a, &b);
    r = 0;
    while (b > 0) {
      r = a % b;
      a = b;
      b = r;
    }
    printf("%d\n", a);
  }
  return 0;
}

#include <stdio.h>

int n, a, b;

int euclid(a, b) {
  if (!b) return a;
  return euclid(b, a % b);
}

int main() {
  freopen("euclid2.in", "r", stdin);
  freopen("euclid2.out", "w", stdout);

  scanf("%d", &n);
  while(n--) {
    scanf("%d%d", &a, &b);
    printf("%d\n", euclid(a, b));
  }

  return 0;
}

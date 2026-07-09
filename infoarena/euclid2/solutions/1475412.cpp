#include <cstdio>

inline int gcd(int a, int b) {
  return !b ? a : gcd(b, a % b);
}

int main() {
  freopen("euclid2.in", "r", stdin);
  freopen("euclid2.out", "w", stdout);
  
  int tests, a, b;
  scanf("%d", &tests);
  for (int test = 1; test <= tests; test++) {
    scanf("%d%d", &a, &b);
    printf("%d\n", gcd(a, b));
  }
  return 0;
}

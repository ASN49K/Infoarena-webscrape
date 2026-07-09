#include <cstdio>

int f(int a, int b) {
  if (b == 0) return a;
  return f(b, a % b);
}

int T; 

int main() {
  freopen("euclid2.in", "r", stdin);
  freopen("euclid2.out", "w", stdout);
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    int a, b; scanf("%d %d", &a, &b);
    printf("%d\n", f(a, b));
  }
  return 0;
}

#include <cstdio>

int main() {
  freopen("nim.in", "r", stdin);
  freopen("nim.out", "w", stdout);
  int t, n, aux, old;
  scanf("%d\n", &t);
  while (t-- > 0) {
    scanf("%d\n", &n);
    old = 0;
    while (n-- > 0) {
      scanf("%d", &aux);
      old ^= aux;
    }
    if (old) {
      printf("DA\n");
    } else {
      printf("NU\n");
    }
  }
  return 0;
}

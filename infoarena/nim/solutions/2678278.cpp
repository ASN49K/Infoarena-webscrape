#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  freopen("nim.in", "r", stdin);
  freopen("nim.out", "w", stdout);
  int t, n, x, X;

  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    X = 0;
    while(n--) {
      scanf("%d", &x);
      X ^= x;
    }
    printf((X == 0) ? "NU\n" : "DA\n");
  }

  return 0;
}

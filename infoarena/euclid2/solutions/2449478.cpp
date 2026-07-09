#include <cstdio>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
  while (b) {
    swap(a, b);
    b %= a;
  }
  return a;
}

int main() {
  freopen ("euclid2.in", "r", stdin);
  freopen ("euclid2.out", "w", stdout);

  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", gcd(a, b));
  }

  return 0;
}

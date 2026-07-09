/**
  *  Worg
  */
#include <cstdio>

FILE *fin = freopen("euclid2.in", "r", stdin); FILE *fout = freopen("euclid2.out", "w", stdout);

int Gcd(int x, int y) {
  int r;
  while(y) {
    r = x % y; x = y; y = r;
  }

  return x;
}

int main() {
  int testCount; scanf("%d", &testCount);

  for(int i = 0; i < testCount; i++) {
    int x, y; scanf("%d%d", &x, &y);

    printf("%d\n", Gcd(x, y));
  }

  return 0;
}

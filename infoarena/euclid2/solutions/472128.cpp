#include <cstdio>

using namespace std;

#define FIN "euclid2.in"
#define FOUT "euclid2.out"

long long gcd(long long a, long long b) {
  while (a && b) {
    a %= b;
    if (a) {
      b %= a;
    }
  }

  return a + b;
}

int main(void) {
  int tests;

  freopen(FIN, "r", stdin);
  freopen(FOUT, "w", stdout);

  scanf("%d", &tests);
  while (tests--) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%lld\n", gcd(a, b));
  }



  return 0;
}

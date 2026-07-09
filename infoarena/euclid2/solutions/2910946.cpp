#include <cstdio>


int __gcd(int a, int b) {
  if (b == 0)
    return a;
  return __gcd(b, a%b);
}

int main()
{  
  freopen("euclid2.in", "r", stdin);
  freopen("euclid2.out", "w", stdout);

  int N;
  scanf("%d", &N);
  int a, b;
  for (int i = 0; i < N; ++i) {
    scanf("%d%d", &a, &b);
    printf("%d\n", __gcd(a, b));
  }
  return 0;
}

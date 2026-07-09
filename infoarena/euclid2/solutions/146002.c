#include <stdio.h>  

int gcd(int a, int b) {
  if (!b) return a;
    return gcd(b, a % b);
}  

int main(void) {
  int a, b;

  freopen("euclid2.in", "r", stdin);
  freopen("euclid2.out", "w", stdout);

  scanf("%d %d", &a, &b);
  printf("%d\n", gcd(a, b));

  return 0;  
}


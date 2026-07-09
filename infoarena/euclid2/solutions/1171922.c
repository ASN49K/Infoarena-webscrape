#include<stdio.h>

int gcd(int a, int b);

int main(void) {
  freopen("euclid2.in", "r", stdin);
  freopen("euclid2.out", "w", stdout);
  int T,a,b;
  scanf("%d", &T);
  while(T-->0){
    scanf("%d %d", &a, &b);
    printf("%d\n", gcd(a,b));
  }
  return 0;
}

int gcd(int a, int b) {
  if(b == 0) return a;
  return gcd(b, a%b);
}

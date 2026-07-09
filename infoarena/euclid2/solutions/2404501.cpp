#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int T, A, B;

int gcd(int a, int b) {
  while (b > 0) {
    int c = b;
    b = a % b;
    a = c;
  }
  return a;
}

int main(void) {
  freopen("euclid2.in", "r", stdin);
  freopen("euclid2.out", "w", stdout);

  scanf("%d", &T);
  for(; T; --T) {
    scanf("%d %d", &A, &B);
    printf("%d\n", gcd(A, B));
  }

  return 0;
}


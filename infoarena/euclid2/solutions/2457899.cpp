#include <stdio.h>

 int t,a,b;
 int gcd(int A, int B) {
 	if (!B) return A;
    return gcd(B, A % B);
 }
  int main (void) {
  	freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
  	scanf("%d", &t);
  	for (;t;t--) {
  		scanf("%d %d", &a, &b);
  		printf("d%\n", gcd(a,b));
	  }
	  return 0;
  }

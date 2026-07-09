#include <stdio.h>

int T, A, B;

int gcd(int a, int b) {
   if (!b) return a;
   return gcd(b, a % b);
}

int main(void) {
   
   scanf("%d", &T);
   for(;T;--T) {
      scanf("%d %d", &A, &B);
      printf("%d\n", gcd(A,B));
   }
   return 0;
}
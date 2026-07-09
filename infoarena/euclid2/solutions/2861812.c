#include <stdio.h>
#define FIN "euclid2.in"
#define FOUT "euclid2.out"

int gcd(int a, int b) {

    while(a != b) {

          if(a > b) {
             a = a - b;
          } else {
             b = b - a;
          }      
    }
  
    return a;
}

int euclid(int a, int b) {
  
    int r;
    while(b!=0) {
       r = a % b;
       a = b;
       b = r;         
    }
  
    return a;
  
}

int main(void) {

   int a, b, count, out;
  
   freopen(FIN, "r", stdin);
   freopen(FOUT, "w", stdout);
  
    scanf("%d", &count);
    while(count--) {
       scanf("%d %d", &a, &b);
       out = euclid(a, b);
       printf("%d\n", out);  
    }

  
      
  return 0;
}
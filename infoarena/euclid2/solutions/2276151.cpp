#include <cstring>
#include <cstdio>

int n, a, b, r;

// To execute C++, please define "int main()"
int main() {
  freopen("euclid2.in","r");
  freopen("euclid2.out","w");
  scanf("%d", &n);
  while(n--) {
    scanf("%d %d", &a, &b);
    r = a % b;
    while (b != 0) {
      r = a % b;
      a = b;
      b = r;
    }
    
    printf("%d\n", a);
  }
  return 0;
}

#include <cstring>
#include <cstdio>

int n, a, b, r;

int main() {
  freopen("euclid2.in","r", stdin);
  freopen("euclid2.out","w", stdout);
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

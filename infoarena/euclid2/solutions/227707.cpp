#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
//    freopen("euclid2.in", "r", stdin);
//    freopen("euclid2.out", "w", stdout);
    int n;
    scanf("%d", &n);    
    while (n--) {
          int a, b;
          scanf("%d %d", &a, &b);
          printf("%d\n", __gcd(a, b));
          }
    return 0;
    }

#include <cstdio>

int main () {
    freopen ("nim.in", "r", stdin);
    freopen ("nim.out", "w", stdout);
    
    int tests;
    scanf ("%d", &tests);
    while (tests--) {
          int s = 0, x, n;
          scanf ("%d", &n);
          for (int i = 0; i < n; ++i) {
              scanf ("%d", &x);
              
              s ^= x;
          }
          
          if (s) printf ("DA\n"); else printf ("NU\n");
    }
    
    return 0;
}

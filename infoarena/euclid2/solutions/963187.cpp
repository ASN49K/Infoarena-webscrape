#include <stdio.h>
 
int t, a, b;
 
int euclid (int a, int b) {
    if (!b) return a;
    return euclid (b, a % b);
}
 
int main (void) {
    freopen ("euclid.in", "r", stdin);
    freopen ("euclid.out", "w", stdout);
     
    scanf ("%d", &t);
     
    for (; t; --t) {
        scanf ("%d %d", &a, &b);
        printf ("%d\n", euclid(a, b));
    }
     
    return 0;
 
}



#include <cstdio>
#include <cstring>

using namespace std;

#define FIN "euclid2.in"
#define FOUT "euclid2.out"

int gcd (int a, int b) {
    if (!b)
       return a;
    else return gcd (b, a % b);
}

int main () {
    freopen (FIN, "r", stdin);
    freopen (FOUT, "w", stdout);
    
    int T;
    
    scanf ("%d", &T);
    
    while (T) {
          int a, b;
          
          scanf ("%d %d", &a, &b);
          printf ("%d\n", gcd (a, b));
          
          --T;
    }
    
    return 0;
}

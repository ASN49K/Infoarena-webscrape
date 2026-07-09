#include <cstdlib>
#include <cstdio>
#include <string>
#include <strings.h>

using namespace std;

int main() {
#ifdef PADREATI
    freopen("in.txt", "r", stdin);
#else
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
#endif
    
    int n, a, b;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &a, &b);
        if (b > a) {
            int c = a;
            a = b;
            b = c;
        }

        while (b > 1) {
            int c = a;
            a = b;
            b = c % b;
        }
        printf("%d\n", b == 1 ? 1 : a);
    }

    return 0;
}


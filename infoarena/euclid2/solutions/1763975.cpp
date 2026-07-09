#include <cstdio>
using namespace std;
inline int cmmdc ( int a, int b ) {
    int r;
    while ( b ) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main() {
    freopen ( "euclid2.in", "r", stdin );
    freopen ( "euclid2.out", "w", stdout );
    int t, a, b;
    scanf ( "%d", &t );
    for ( register int i = 1 ; i <= t ; ++ i ) {
        scanf ( "%d%d", &a, &b );
        printf ( "%d\n", cmmdc ( a, b ) );
    }
    return 0;
}

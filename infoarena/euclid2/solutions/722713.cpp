#include <cstdio>

using namespace std;

long long euclid ( long long a, long long b ) {
    long long r = a%b;
    while (r) {
        a = b;
        b = r;
        r = a%b;
    }
    return b;
}

int main () {
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int t;
    long long a, b;
    scanf ("%d", &t);
    for (int i=1; i<=t; ++i) {
        scanf ("%lld%lld", &a, &b);
        printf ("%lld\n", euclid(a,b));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

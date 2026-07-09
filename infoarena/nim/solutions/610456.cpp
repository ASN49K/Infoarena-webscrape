#include <cstdio>

inline void rezolva() {
    int n, x, r = 0;

    for(scanf("%d",&n); n > 0; --n) {
        scanf("%d",&x);
        r ^= x;
    }

    fputs(((r!=0) ? "DA\n" : "NU\n"), stdout);
}

int main() {
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);

    int T;
    for(scanf("%d",&T); T > 0; --T)
        rezolva();

    return 0;
}

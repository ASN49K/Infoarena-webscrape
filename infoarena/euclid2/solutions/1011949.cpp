#include <cstdio>

using namespace std;

inline int cmmdc(int a, int b) {
    int t;

    while (b > 0) {
        t = b;
        b = a%b;
        a = t;
    }

    return a;
}

int main() {
    int N, a, b, i;

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &N);
    for (i = 0; i < N; ++i) {
        scanf("%d%d", &a, &b);

        printf("%d\n", cmmdc(a, b));
    }

    return 0;
}

#include <cstdio>

using namespace std;

int cmmdc(int a, int b) {
    int c;
    while(b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int n, x, y;
    scanf("%d", &n);

    for( ; n; -- n) {
        scanf("%d%d", &x, &y);
        printf("%d\n", cmmdc(x, y));
    }

    return 0;
}

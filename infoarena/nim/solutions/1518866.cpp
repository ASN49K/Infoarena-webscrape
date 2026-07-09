#include <cstdio>

using namespace std;

int main() {
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);

    int t, n, xo, x;
    scanf("%d", &t);

    while(t--) {
        xo = 0;
            scanf("%d", &n);
        for(int i = 1; i <= n; ++ i) {
            scanf("%d", &x);
            xo ^= x;
        }
        if(xo == 0) {
            printf("NU\n");
        }
        else
            printf("DA\n");
    }

    return 0;
}

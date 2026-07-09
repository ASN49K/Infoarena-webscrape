#include <fstream>

using namespace std;

#define FIN "euclid2.in"
#define FOUT "euclid2.out"

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve() {
    int T;
    for (scanf("%d", &T); T; --T) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", gcd(a, b));
    }
}

int main() {
    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);
    solve();
    return 0;
}

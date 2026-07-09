#include <cstdio>

using namespace std;

int n, a, b;

int cmmdc(int a, int b) {
    return (b == 0) ? a : cmmdc(b, a % b);
}

int main()
{
    freopen ("euclid2.in", "r", stdin);
    freopen ("euclid2.out", "w", stdout);
    
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &a, &b);
        printf("%d\n", cmmdc(a, b));
    }
}

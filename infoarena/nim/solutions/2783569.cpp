#include <cstdio>

using namespace std;

int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);
    int t, n, xorsum, x;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        xorsum = 0;
        for(int i = 1; i <= n; i++)
            scanf("%d", &x),
            xorsum ^= x;
        printf("%s\n", xorsum ? "DA" : "NU");
    }
    return 0;
}

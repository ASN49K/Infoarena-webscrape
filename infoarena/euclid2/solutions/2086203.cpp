#include <iostream>
#include <cstdio>

using namespace std;

int e(int a, int b) {
    int r = 0;
    while(b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    long n, a, b, r;
    scanf("%d", &n);
    for(int i = 1;i <= n;i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", e(a, b));
    }
    return 0;
}

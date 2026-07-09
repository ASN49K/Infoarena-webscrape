#include <bits/stdc++.h>

using namespace std;



int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", __gcd(a, b));
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int N, a,b;
    scanf("%d",&N);
    while(N --) {
        scanf("%d%d",&a,&b);
        printf("%d\n", __gcd(a,b));
    }
    return 0;
}

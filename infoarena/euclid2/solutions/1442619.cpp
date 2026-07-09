#include <bits/stdc++.h>
using namespace std;

int n,a,b;

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d%d", &a, &b);
        printf("%d\n", __gcd(a,b));
    }
    return 0;
}

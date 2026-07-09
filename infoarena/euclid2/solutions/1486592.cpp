#include <bits/stdc++.h>

using namespace std;

int n;

int cmmdc(int a, int b)
{
    int rest = 0;
    while (b)
    {
        rest = a % b;
        a = b;
        b = rest;
    }
    return a;
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1, a, b; i <= n; i++)
        scanf("%d %d", &a, &b),
        printf("%d\n", cmmdc(a, b));
    return 0;
}

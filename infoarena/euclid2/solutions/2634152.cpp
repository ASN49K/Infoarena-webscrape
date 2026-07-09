#include <bits/stdc++.h>

using namespace std;

int main()  {
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int n;
    scanf("%d", &n);
    while(n--)  {
        int a, b;
        scanf("%d%d", &a, &b);
        while(b)  {
            int r = a % b;
            a = b;
            b = r;
        }
        printf("%d\n", a);
    }
    return 0;
}

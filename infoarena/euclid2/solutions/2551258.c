#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, a, b;

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", n);

    while(n>0)
    {
        scanf("%d", &a, &b);
        printf("%d", gcd(a,b));
    }


    return 0;
}

int gcd(int a, int b)
{
    if(!b) return a;
    return gcd(b, a%b);
}

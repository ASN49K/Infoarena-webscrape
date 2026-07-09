#include <stdio.h>
#include <stdlib.h>
int gcd(int a, int b);
int main()
{
    int n, a, b;

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &n);

    for(;n!=0; n--)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", gcd(a,b));
    }


    return 0;
}

int gcd(int a, int b)
{
    if(!b) return a;
    return gcd(b, a%b);
}

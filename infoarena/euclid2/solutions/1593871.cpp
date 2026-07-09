#include <stdio.h>
#include <iostream>
using namespace std;
int T, A, B;

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main(void)
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d",&T);
    for (; T; --T)
    {
        scanf("%d",&A);
        scanf("%d",&B);
        printf("%d",gcd(A,B));
        printf("\n");
    }

    return 0;
}

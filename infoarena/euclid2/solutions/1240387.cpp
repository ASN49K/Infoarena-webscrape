#include <stdlib.h>
#include <stdio.h>


int euclid(int, int);

int main()
{

    freopen("euclid2.in", "r",stdin);
    freopen("euclid2.out", "w",stdout);

    int a = 0, b = 0, T = 0;
    int gcd = 0;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d %d", &a, &b);
        gcd = euclid(a, b);
        printf("%d\n", gcd);
    }


    return 0;
}

int euclid(int a, int b)
{
    while(a) {
        b = b % a;
        a = a + b - (b = a);
    }
    return b;
}

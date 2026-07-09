#include <stdio.h>

int T, A, B;

int euclid(int a, int b)
{
    if (!b) return a;
    return euclid(b, a % b);
}

int main(void)
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &T);
    for (; T; --T)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", euclid(A, B));
    }        

    return 0;
}

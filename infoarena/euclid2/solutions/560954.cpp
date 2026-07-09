#include <stdio.h>
int T,M,N;
int eu(int a, int b)
{
    if (!b) return a;
    return eu(b, a % b);
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &T);
    for (; T; --T)
    {
        scanf("%d %d", &M, &N);
        printf("%d\n", eu(M, N));
    }        

    return 0;
}


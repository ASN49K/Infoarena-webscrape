#include <stdio.h>

int T, A, B;

int euclid(int a, int b)
{
    if(!b) return a;
    return euclid(b, a%b);
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &T);
    for(int i=T;i>0;i--)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", euclid(A,B));
    }
    return 0;
}

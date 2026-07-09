#include <stdio.h>

int T, A, B;

int gcd(int X, int Y)
{
    if (Y == 0)
    {
        return X;
    }
    else
        return gcd(Y, X % Y);
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", gcd(A, B));
    }
}

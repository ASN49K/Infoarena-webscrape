#include <stdio.h>

long int euclid(long int a, long int b)
{

    while(a != 0 && b != 0)
        if(a >= b)
            a = a % b;
        else
            b = b % a;
    if(a == 0)
        return b;
    return a;
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    long int a, b, i, n;

    scanf("%ld", n);

    for(i = 0; i < n; i++)
    {
        scanf("%ld", &a);
        scanf("%ld", &b);
        printf("%ld",euclid(a, b));
    }

    return 0;
}

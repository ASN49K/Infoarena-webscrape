#include <stdio.h>

int euclid(int a, int b)
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
        scanf("%d", &a);
        scanf("%d", &b);
        printf("%d",euclid(a, b));
    }

    return 0;
}

#include <stdio.h>

int t, a, b;

int Cmmdc(int a, int b);

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &t);
    while ( t )
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", Cmmdc(a, b));
        t--;
    }
    return 0;
}

int Cmmdc(int a, int b)
{
    if ( a == 0 ) return b;
    if ( b == 0 ) return b;
    if ( a < b ) a = a+b, b = a-b, a = a-b;
    if ( a%b == 0 ) return b;
    return Cmmdc(a%b, b);
}

            

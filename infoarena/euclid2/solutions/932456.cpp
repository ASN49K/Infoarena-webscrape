#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

int gcd (int a, int b)
{
    int c = (a > b) ? a : b;
    b = a + b - c;
    a = c;
    while(b > 0)
    {
        c = b;
        b = a % b;
        a = c;
    }
    return a;
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int T;
    int a, b, c;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", gcd(a,b));
    }

    return 0;
}

#include <iostream>
#include <cstdio>

using namespace std;

int euclid (int a, int b)
{
    int c;

    while (b!=0)
    {
        c = a%b;
        a = b;
        b = c;

    }

    return a;
}



int main()
{

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int q, i, a, b;

    scanf("%d", &q);

    for (i = 1; i<= q; i++)
    {
        scanf("%d %d", &a, &b);

        printf("%d\n", euclid(a, b));
    }

    return 0;
}

#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int a, int b)
{
    int r;

    r = a%b;
    while (r)
    {
        a = b;
        b = r;
        r = a%b;
    }

    return b;
}

int main()
{
    int n, a, b;

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &n);

    for (; n; --n)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", cmmdc(a, b));
    }

    return 0;
}

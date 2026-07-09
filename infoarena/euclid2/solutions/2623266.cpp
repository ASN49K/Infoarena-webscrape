#include <cstdio>
#include <algorithm>

int gcd(int a, int b)
{
    if (a > b)
        std::swap(a, b);

    int r = b % a;
    while (r)
    {
        b = a;
        a = r;
        r = b % a;
    }
    return a;
}


int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int numer_of_requests{};
    int a{}, b{};
    scanf("%d", &numer_of_requests);

    while (numer_of_requests--)
    {
        scanf("%d%d", &a, &b);
        printf("%d\n", gcd(a, b));
    }

}
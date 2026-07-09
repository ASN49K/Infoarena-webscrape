#include <cstdio>

using namespace std;

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int t, a, b, d;

    scanf("%d", &t);
    while(t)
    {
        scanf("%d%d", &a, &b);
        while(b)
        {
            d=a%b;
            a=b;
            b=d;
        }
        printf("%d\n", a);
        t--;
    }

    return 0;
}

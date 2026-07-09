#include <cstdio>

using namespace std;

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int a, b, r, n;

    scanf("%d", &n);
    while(n)
    {
        scanf("%d%d", &a, &b);
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        printf("%d\n", a);
        n--;
    }

    return 0;
}

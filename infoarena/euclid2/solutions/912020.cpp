#include <cstdio>

using namespace std;

int cmmdc(int x, int y)
{
    while(y)
    {
        int r = x % y;
        x = y;
        y = r;
    }

    return x;
}

int main()
{
    int t;
    int x;
    int y;

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d\n", &t);
    while(t --)
    {
        scanf("%d %d\n", &x, &y);
        printf("%d\n", cmmdc(x, y));
    }

    return 0;
}

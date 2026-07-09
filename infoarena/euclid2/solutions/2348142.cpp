#include <cstdio>
using namespace std;

int cmmdc (int x, int y)
{
    if (x == 0 || y == 0) {return 1;}
    if (x < 0) {x*=-1;}
    if (y < 0) {y*=-1;}
    if (x == y) {return x;}
    if (x%2 + y%2 == 0) {return 2 * cmmdc (x/2, y/2);}
    if (x%2 == 0) {return cmmdc (x/2, y);}
    if (y%2 == 0) {return cmmdc (x, y/2);}
    return (x > y) ? cmmdc ((x-y)/2, y) : cmmdc (x, (y-x)/2);
}

int main()
{
    freopen ("euclid2.in", "r", stdin);
    freopen ("euclid2.out", "w", stdout);

    int n, i, x, y;
    scanf ("%d", &n);
    for (i = 0; i < n; ++i)
    {
        scanf ("%d%d", &x, &y);
        printf ("%d\n", cmmdc (x, y));
    }

    return 0;
}

#include <cstdio>

using namespace std;

int t, a, b;

int cmmdc(int x, int y)
{
    int r;
    while(y)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

int main()
{

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &t);

    for(int i=1; i<=t; i++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", cmmdc(a, b));
    }

    return 0;
}

#include <cstdio>

using namespace std;

int euclid(int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int t;

    scanf("%d", &t);
    while(t)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", euclid(a, b));
    }

    return 0;
}

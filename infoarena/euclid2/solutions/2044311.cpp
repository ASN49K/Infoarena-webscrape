#include <cstdio>

using namespace std;
int a, b;

int cmmdc(int x, int y)
{
    if(y == 0)
        return x;
    return cmmdc(y, x%y);
}

int n;
int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", cmmdc(a, b));
    }
    return 0;
}

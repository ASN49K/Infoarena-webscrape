#include <cstdio>

using namespace std;

int gcd(int x, int y)
{
    int r;
    while(y>0)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

int i, t, a, b;

int main()
{
    freopen("pc.in", "r", stdin);
    freopen("pc.out", "w", stdout);
    scanf("%d", &t);
    for(i=1; i<=t; i++)
    {
        scanf("%d%d", &a, &b);
        printf("%d\n", gcd(a, b));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

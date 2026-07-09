#include <cstdio>

using namespace std;
int t, n, a, xorsum;

int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d", &n);

        xorsum = 0;
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d", &a);
            xorsum = xorsum ^ a;
        }

        if(xorsum)
            printf("DA\n");
        else
            printf("NU\n");
    }

    return 0;
}

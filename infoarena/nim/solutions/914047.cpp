#include <cstdio>

using namespace std;

int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);

    int t;
    int n;
    int x;

    scanf("%d\n", &t);

    while(t --)
    {
        scanf("%d\n", &n);

        int s = 0;

        while(n --)
        {
            scanf("%d ", &x);

            s ^= x;
        }

        if(!s)
            printf("NU\n");
        else
            printf("DA\n");
    }

    return 0;
}

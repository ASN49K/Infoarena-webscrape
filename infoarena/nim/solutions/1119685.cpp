#include <cstdio>

using namespace std;

int nim_sum, n, t, x;

int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);

    scanf("%d", &t);
    while( t-- )
    {
        nim_sum = 0;
        scanf("%d", &n);
        while ( n-- )
        {
            scanf("%d", &x);
            nim_sum ^= x;
        }

        if( nim_sum )
            printf("DA\n");
        else
            printf("NU\n");
    }


    return 0;
}

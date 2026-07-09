#include <stdio.h>

int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);
    int n,t;
    scanf("%d", &n);
    for( ;n; n--)
    {
        scanf("%d", &t);
        int primul_termen;
        scanf("%d", &primul_termen);
        int XOR = primul_termen, x;
        t--;
        for(;t ;t--)
            {
                scanf("%d", &x);
                XOR ^= x;
            }
        if(XOR > 0)
            printf("DA\n");
                else
                    printf("NU\n");
    }
    return 0;
}
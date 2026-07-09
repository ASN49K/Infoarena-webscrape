#include <stdio.h>

int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);

    int T, N, x, S;

    scanf("%d", &T);

    for(;T--;)
    {
        scanf("%d", &N);

        S = 0;

        for(;N--;)
        {
            scanf("%d", &x);

            S ^= x;
        }
        puts(S ? "DA" : "NU");
    }
    return 0;
}

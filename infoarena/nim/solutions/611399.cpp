#include <cstdio>

#define FIN "nim.in"
#define FOUT "nim.out"

int T, N, R;

int  main()
{
    int i, j, x;

    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);

    scanf("%d", &T);

    for (i = 1; i <= T; ++ i)
    {
        scanf("%d", &N);

        for (j = 1, R = 0; j <= N; ++ j)
            scanf("%d", &x), R ^= x;

        printf(R ? "DA\n" : "NU\n");
    }
}

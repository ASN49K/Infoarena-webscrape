#include <stdio.h>

char buffer[10000000]; int p = -1;

__attribute__((always_inline)) int get_int()
{
    int nr = 0;

    for(++p; buffer[p] < 48; ++p);

    for(; buffer[p] > 47; ++p)

        nr = nr * 10 + buffer[p] - 48;

    return nr;
}

int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);

    fread(buffer, 1, 10000000, stdin);

    int T, N, x, S;

    T = get_int();

    for(;T--;)
    {
        N = get_int();

        S = 0;

        for(;N--;)
        {
            x = get_int();

            S ^= x;
        }
        puts(S ? "DA" : "NU");
    }
    return 0;
}

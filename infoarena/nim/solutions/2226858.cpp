#include <stdio.h>

char buffer[10000000]; int p = -1;

__attribute__((always_inline)) int get_int()
{
    int nr = 0, c = getchar();

    for(; c < 48 | c > 57; c = getchar());

    for(; c > 47 & c < 58; nr = nr * 10 + c - 48, c = getchar());

    return nr;
}

int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);

    ///fread(buffer, 1, 10000000, stdin);

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

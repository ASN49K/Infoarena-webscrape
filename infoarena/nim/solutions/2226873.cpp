#include <stdio.h>

char buffer[4600000]; int p = -1;

__attribute__((always_inline)) int get_int()
{
    int number = 0;

    for(++p; buffer[p] < 48; ++p);

    for(; buffer[p] > 47; ++p)

        number = number * 10 + buffer[p] - 48;

    return number;
}

int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);

    fread(buffer, 1, 4600000, stdin);

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

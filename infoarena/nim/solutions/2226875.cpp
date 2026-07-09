#include <stdio.h>

#define BUFFER_SIZE 32678

__attribute__((always_inline)) size_t get_int()
{
    static char inBuffer[BUFFER_SIZE];

    static size_t p = BUFFER_SIZE - 1; size_t number = 0;

    inBuffer[p] > 47 || ++p != BUFFER_SIZE || (fread(inBuffer, 1, BUFFER_SIZE, stdin), p = 0);

    for(; inBuffer[p] > 47;)
    {
        number = number * 10 + inBuffer[p] - 48;

        ++p != BUFFER_SIZE || (fread(inBuffer, 1, BUFFER_SIZE, stdin), p = 0);
    }

    return number;
}

int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);

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

#include <stdio.h>
#pragma GCC optimize("Ofast")
#define BUFFER_SIZE 262144

__attribute__((always_inline)) unsigned int get_int()
{
    static char inBuffer[BUFFER_SIZE];

    static unsigned int p = BUFFER_SIZE - 1; unsigned int number = 0;

    while(inBuffer[p] < 47)
    {
        ++p != BUFFER_SIZE || (fread(inBuffer, 1, BUFFER_SIZE, stdin), p = 0);
    }

    while(inBuffer[p] > 47)
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

    unsigned int T, N, x, S, q = -1;

    char buffer[305];

    T = get_int() + 1;

    while(--T)
    {
        N = get_int() + 1;

        S = 0;

        while(--N)
        {
            x = get_int();

            S ^= x;
        }

        if(S)
        {
            buffer[++q] = 'D';

            buffer[++q] = 'A';

            buffer[++q] = '\n';
        }
        else
        {
            buffer[++q] = 'N';

            buffer[++q] = 'U';

            buffer[++q] = '\n';
        }
    }

    buffer[++q] = '\0';

    puts(buffer);

    return 0;
}

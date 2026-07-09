#include <stdio.h>

#define BUFFER_SIZE 262144

__attribute__((always_inline)) int get_int()
{
    static char inBuffer[BUFFER_SIZE];

    static int p = BUFFER_SIZE - 1; int number = 0;

    for(; inBuffer[p] < 47;)
    {
        ++p != BUFFER_SIZE || (fread(inBuffer, 1, BUFFER_SIZE, stdin), p = 0);
    }

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

    int T, N, x, S, q = -1;

    char buffer[305];

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

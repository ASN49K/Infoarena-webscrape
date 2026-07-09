#include <cstdio>

static char inBuffer[32768];

static int p = 0;

__attribute__((always_inline)) int get_nr()
{
    int num = 0;

    while(inBuffer[p] < 48 | inBuffer[p] > 57)
    {
        ++p != 32768 || (fread(inBuffer, 1, 32768, stdin), p = 0);
    }

    while(inBuffer[p] > 47 & inBuffer[p] < 58)
    {
        num = num * 10 + inBuffer[p] - 48;

        ++p != 32768 || (fread(inBuffer, 1, 32768, stdin), p = 0);
    }

    return num;
}

char outBuffer[1100005]; int p1 = 1100004;

__attribute__((always_inline)) void itoa(int x)
{
    while(x)
    {
        outBuffer[--p1] = x % 10 + 48;

        x /= 10;
    }

    outBuffer[--p1] = 10;
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int T = get_nr() + 1, a, b, v[100001];

    for(int i = T; --i; v[i] = a)
    {
        a = get_nr();

        b = get_nr();

        for(int t; b; t = b, b = a % b, a = t);
    }

    for(int i = 1; i != T;) itoa(v[i++]);

    puts(outBuffer + p1 + 1);
}

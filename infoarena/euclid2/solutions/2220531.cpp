#include <cstdio>

#define floor_log10(N) (((N) > 999999999) + ((N) > 99999999) + ((N) > 9999999) + ((N) > 999999) + ((N) > 99999) + ((N) > 9999) + ((N) > 999) + ((N) > 99) + ((N) > 9))

int gcd(int a, int b)
{
    int t;

    while(b)
    {
        t = b;

        b = a % b;

        a = t;
    }

    return a;
}

static char inBuffer[0x8000];

static int p = 0x0;

__attribute__((always_inline)) int get_nr()
{
    int num = 0x0;

    while(inBuffer[p] < 0x30 | inBuffer[p] > 0x39)
    {
        ++p != 0x8000 || (fread(inBuffer, 0x1, 0x8000, stdin), p = 0x0);
    }

    while(inBuffer[p] > 0x2F & inBuffer[p] < 0x3A)
    {
        num = num * 0xA + inBuffer[p] - 0x30;

        ++p != 0x8000 || (fread(inBuffer, 0x1, 0x8000, stdin), p = 0x0);
    }

    return num;
}

char outBuffer[0x10C8E5]; int p1 = ~0x0;

__attribute__((always_inline)) void itoa(int x)
{
    int digits = 2 + floor_log10(x);

    for(int i = digits, y; --i; x = y)
    {
        outBuffer[p1 + i] = x - 0xA * (y = x / 0xA) + 0x30;
    }

    outBuffer[p1 = p1 + digits] = 0xA;
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int T = get_nr() + 1, a, b;

    while(--T)
    {
        a = get_nr();

        b = get_nr();

        for(int t; b; t = b, b = a % b, a = t);

        itoa(a);
    }

    fwrite(outBuffer, 1, p1, stdout);
}

#include <cstdio>

__attribute__((always_inline)) unsigned int gcd(unsigned int a, unsigned int b)
{
    for(int t; b;)
    {
        t = b; b = a % b; a = t;
    }

    return a;
}

__attribute__((always_inline)) unsigned int get_number()
{
    static char inBuffer[0x20000];

    static unsigned int p = 0x1FFFF; unsigned int number = 0x0;

    inBuffer[p] > 0x2F || (++p != 0x20000) || (fread(inBuffer, 0x1, 0x20000, stdin), p = 0x0);

    for(;inBuffer[p] > 0x2F;)
    {
        number = number * 0xA + inBuffer[p] - 0x30;

        ++p != 0x20000 || (fread(inBuffer, 0x1, 0x20000, stdin), p = 0x0);
    }

    return number;
}

char outBuffer[0x100000]; unsigned int p = ~0x0;

__attribute__((always_inline)) void put_number(unsigned int x)
{
    unsigned int digits = x > 0x3B9AC9FF ? 0xB :
                          x > 0x5F5E0FF  ? 0xA :
                          x > 0x98967F   ? 0x9 :
                          x > 0xF423F    ? 0x8 :
                          x > 0x1869F    ? 0x7 :
                          x > 0x270F     ? 0x6 :
                          x > 0x3E7      ? 0x5 :
                          x > 0x63       ? 0x4 :
                          x > 0x9        ? 0x3 : 0x2;

    for(unsigned int i = digits; --i; x /= 0xA)
    {
        outBuffer[p + i] = x % 0xA + 0x30;
    }

    outBuffer[p = p + digits] = 0xA;
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    for(unsigned int N = -~get_number(); --N;)
    {
        put_number(gcd(get_number(), get_number()));
    }

    fwrite(outBuffer, 0x1, p, stdout);

    return 0x0;
}

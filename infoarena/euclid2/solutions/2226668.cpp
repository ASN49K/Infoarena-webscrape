#include <cstdio>

#define BUFFER_SIZE 10000000

char buffer[BUFFER_SIZE], q = -1;

__attribute__((always_inline)) unsigned int get_number()
{
    int number = 0;

    for(++q; buffer[q] > 47; ++q)
    {
        number = number * 10 + buffer[q] - 48;
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


__attribute__((always_inline)) unsigned int gcd(unsigned int a, unsigned int b)
{
    for(int t; b;)
    {
        t = b; b = a % b; a = t;
    }

    return a;
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    fread(buffer, 1, BUFFER_SIZE, stdin);

    for(unsigned int N = -~get_number(); --N;)
    {
        put_number(gcd(get_number(), get_number()));
    }

    fwrite(outBuffer, 0x1, p, stdout);

    return 0x0;
}

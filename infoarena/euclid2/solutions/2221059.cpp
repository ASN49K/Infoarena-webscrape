#include <cstdio>

__attribute__((always_inline)) int gcd(int a, int b)
{
    for(int t; b;)
    {
        t = b; b = a % b; a = t;
    }

    return a;
}

__attribute__((always_inline)) int get_number()
{
    static char inBuffer[0x10000];

    static int p = 0xFFFF; int number = 0x0;

    inBuffer[p] > 0x2F || ++p != 0x10000 || (fread(inBuffer, 0x1, 0x10000, stdin), p = 0x0);

    for(;inBuffer[p] > 0x2F;)
    {
        number = number * 0xA + inBuffer[p] - 0x30;

        ++p != 0x10000 || (fread(inBuffer, 0x1, 0x10000, stdin), p = 0x0);
    }

    return number;
}

char outBuffer[0x100000]; int p = ~0x0;

__attribute__((always_inline)) void put_number(int x)
{
    int digits = x > 0x3B9AC9FF ? 0xB :
                 x > 0x5F5E0FF  ? 0xA :
                 x > 0x98967F   ? 0x9 :
                 x > 0xF423F    ? 0x8 :
                 x > 0x1869F    ? 0x7 :
                 x > 0x270F     ? 0x6 :
                 x > 0x3E7      ? 0x5 :
                 x > 0x63       ? 0x4 :
                 x > 0x9        ? 0x3 : 0x2;

    for(int i = digits; --i; x /= 0xA)
    {
        outBuffer[p + i] = x % 0xA + 0x30;
    }

    outBuffer[p = p + digits] = 0xA;
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    for(int N = -~get_number(); --N;)
    {
        put_number(gcd(get_number(), get_number()));
    }

    fwrite(outBuffer, 0x1, p, stdout);

    return 0x0;
}

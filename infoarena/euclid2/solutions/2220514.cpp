#include <cstdio>

using uint32_t = unsigned int;

uint32_t gcd(uint32_t a, uint32_t b)
{
    uint32_t t;

    while(b)
    {
        t = b;

        b = a % b;

        a = t;
    }

    return a;
}
static char inBuffer[0x8000];

static uint32_t p = 0x0;

__attribute__((always_inline)) uint32_t get_nr()
{
    uint32_t num = 0x0;

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

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    uint32_t T = get_nr() + 1;

    //auto s = clock();

    while(--T)
    {
        //gcd(a, b);
        printf("%d\n", gcd(get_nr(), get_nr()));
    }

    //auto e = clock();

    //auto t = 1000.0 * (e - s) / CLOCKS_PER_SEC;

    //cout << "" << t << "ms" << endl;
}

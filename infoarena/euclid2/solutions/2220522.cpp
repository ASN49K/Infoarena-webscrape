#include <cstdio>

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

char outBuffer[0x4C4B40]; int p1 = ~0x0;

__attribute__((always_inline)) void itoa(int x)
{
    if(0x4C4B40 - p1 < 12) puts(outBuffer), p1 = ~0x0;

    int digits = x > 0x3B9AC9FF ? 0xB :
                 x > 0x5F5E0FF  ? 0xA :
                 x > 0x98967F   ? 0x9 :
                 x > 0xF423F    ? 0x8 :
                 x > 0x1869F    ? 0x7 :
                 x > 0x270F     ? 0x6 :
                 x > 0x3E7      ? 0x5 :
                 x > 0x63       ? 0x4 :
                 x > 0x9        ? 0x3 : 0x2;

    for(unsigned int i = digits, y; --i; x = y)
    {
        outBuffer[p1 + i] = x - 0xA * (y = x / 0xA) + 0x30;
    }

    outBuffer[p1 = p1 + digits] = 0x10;
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int T = get_nr() + 1;

    //auto s = clock();

    while(--T)
    {
        //gcd(a, b);
        itoa(gcd(get_nr(), get_nr()));
    }

    puts(outBuffer);

    //auto e = clock();

    //auto t = 1000.0 * (e - s) / CLOCKS_PER_SEC;

    //cout << "" << t << "ms" << endl;
}

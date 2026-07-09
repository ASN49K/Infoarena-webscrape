#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

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

__attribute__((always_inline)) void read(unsigned int &num)
{
    static char inBuffer[0x8000];

    static unsigned int p = 0x0; num = 0x0;

    while(inBuffer[p] < 0x30 | inBuffer[p] > 0x39)
    {
        ++p != 0x8000 || (fread(inBuffer, 0x1, 0x8000, stdin), p = 0x0);
    }

    while(inBuffer[p] > 0x2F & inBuffer[p] < 0x3A)
    {
        num = num * 0xA + inBuffer[p] - 0x30;

        ++p != 0x8000 || (fread(inBuffer, 0x1, 0x8000, stdin), p = 0x0);
    }
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    unsigned int T, a, b;

    //auto s = clock();

    read(T);

    while(T--)
    {
        read(a);

        read(b);
        //gcd(a, b);
        printf("%d\n", gcd(a, b));
    }

    //auto e = clock();

    //auto t = 1000.0 * (e - s) / CLOCKS_PER_SEC;

    //cout << "" << t << "ms" << endl;
}

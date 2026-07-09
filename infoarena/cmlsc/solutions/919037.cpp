#include <cstdio>
#include <algorithm>
#define N 100001

using namespace std;

int a[N], b[N], c[N], n, lg;

void prelucrare()
{
    for (int i = 0; i < n; i++)
    {
        int pos = upper_bound(b, b + lg, a[i]) - b;
        if (pos >= 0 && pos < lg)
        {
            if (b[pos - 1] == a[i])
                continue;
            b[pos] = a[i];
            c[i] = pos;
        }
        else
        {
            if (b[lg - 1] == a[i])
                continue;
            b[lg ++] = a[i];
            c[i] = lg - 1;
        }
    }
}

void read()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d", &a[i]);
}

void print(int i)
{
    if (i < 0 || lg < 0)
        return;
    while (i >= 0)
    {
        if (c[i] == lg)
        {
            lg--;
            print(i - 1);
            printf("%d ", a[i]);
            return;
        }
        i--;
    }
}

int main()
{
    freopen ("scmax.in", "r", stdin);
    freopen ("scmax.out", "w", stdout);
    read();
    prelucrare();
    printf("%d\n", lg);
    lg--;
    print(n - 1);

    return 0;
}

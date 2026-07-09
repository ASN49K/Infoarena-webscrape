#include <iostream>

#include <cstdio>

using namespace std;

FILE *f, *g;

int a, b;

int cmmdc(int a, int b)
{
    int r;

    while(b)
    {
        r = a % b;

        a = b;

        b = r;
    }

    return a;
}

int n;

void solve()
{
    f = fopen("euclid2.in", "r");
    g = fopen("euclid2.out", "w");

    fscanf(f, "%d", &n);

    int i, a, b;

    for(i = 1; i <= n; i ++)
    {
        fscanf(f, "%d%d", &a, &b);

        fprintf(g, "%d\n", cmmdc(a, b));
    }

    fclose(f);
    fclose(g);
}

int main()
{
    solve();

    return 0;
}

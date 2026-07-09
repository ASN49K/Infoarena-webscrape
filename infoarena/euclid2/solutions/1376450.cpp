#include <cstdio>

using namespace std;

int cmmdc(int a, int b)
{
    int r;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    FILE *in = fopen("euclid2.in", "r");
    FILE *out = fopen("euclid2.out", "w");

    int n;
    fscanf(in, "%d", &n);
    int x, y;
    while (n--)
    {
        fscanf(in, "%d%d", &x, &y);
        fprintf(out, "%d\n", cmmdc(x, y));
    }

    return 0;
}

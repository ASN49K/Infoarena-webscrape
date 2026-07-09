#include <stdio.h>

using namespace std;

int euclid (int a, int b)
{
    int r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    FILE *in, *out;
    in = fopen ("euclid2.in", "r");
    out = fopen ("euclid2.out", "w");
    int n;
    fscanf (in, "%d", &n);
    int i;
    int a, b;
    for (i = 1; i <= n; i++)
    {
        fscanf (in, "%d%d", &a, &b);
        fprintf (out, "%d\n", euclid (a, b));
    }
    return 0;
}

#include <stdio.h>

long GCD(long a, long b)
{
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);

}

int main ()
{
    FILE *f = fopen("euclid2.in", "rt");
    FILE *g = fopen("euclid2.out", "wt");

    int i, n;
    long a, b;

    fscanf(f, "%d", &n);

    for (i = 0; i < n; i++)
    {
        fscanf(f, "%ld %ld", &a, &b);
        fprintf(g, "%d\ld", GCD(a, b));
    }

    fclose(f);
    fclose(g);

    return 0;
}

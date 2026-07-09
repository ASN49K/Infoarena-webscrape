#include <stdio.h>

int GCD(long a, long b)
{
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);

}

int main ()
{
    FILE *f = fopen("euclid2.in");
    FILE *g = fopen("euclid2.out");

    int i, n;
    long a, b;

    fscanf(f, "%d", &n);

    for (i = 0; i < n; i++)
    {
        fscanf(f, "%d %d", &a, &b);
        fprintf(g, "%d\n", GCD(a, b));
    }

    fclose(f);
    fclose(g);

    return 0;
}

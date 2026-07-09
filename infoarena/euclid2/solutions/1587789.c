#include <stdio.h>
#include <stdlib.h>

#define INPUT "euclid2.in"
#define OUTPUT "euclid2.out"

int     eu(int a, int b)
{
    if (b == 0)
        return (a);
    else
        eu(b, a % b);
}

int     erato_arr(int *v, int n)
{
    int     i;
    int     dm;

    dm = v[0];
    for (i = 1; i < n; i++)
        dm = (eu(dm, v[i]));
    return (dm);
}
/*
int     read(int *v)
{
    int     n;
    int     i;
    FILE    *in;

    in = fscanf(INPUT, "r");
    fscanf(in, "%d", &n);
    for (i = 0; i < n; i++)
        fscanf(in, "%d", v + i);
    return (n);
}
*/

int     main()
{
    FILE    *in;
    FILE    *out;
    int     i;
    int     n;
    int     a;
    int     b;

    in = fopen(INPUT, "r");
    out = fopen(OUTPUT, "w");
    fscanf(in, "%d", &n);
    for (i = 0; i < n; i++)
    {
        fscanf(in, "%d %d", &a, &b);
        fprintf(out, "%d\n", eu(a, b));
    }
    fclose(in);
    fclose(out);
}

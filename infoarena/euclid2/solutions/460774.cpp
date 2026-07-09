#include <stdio.h>

long int a, b;
long int n, i;

long int cmmdc (long int x, long int y)
{
    long int r;
    while (y)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main ()
{
    FILE *f = fopen ("euclid2.in","r");
    FILE *g = fopen ("euclid2.out","w");
    fscanf (f,"%ld", &n);

    for (i=1; i<=n; ++i)
    {
        fscanf (f,"%ld %ld", &a, &b);
        fprintf (g,"%ld\n", cmmdc (a, b));
    }


    fclose(g);
    fclose(f);
    return 0;
}


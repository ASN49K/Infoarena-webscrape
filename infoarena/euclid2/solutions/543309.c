#include <stdio.h>
#include <conio.h>

int cmmdc(int a, int b)
{
    if (b == 0)
        return a;
    return cmmdc(b, a % b);
}

int main()
{
    int a, b, T, i;
    FILE *in, *out;
    in = fopen("euclid2.in", "rt");
    out = fopen("euclid2.out", "wt");
    fscanf(in, "%i", &T);
    for (i=0; i<T; i++)
    {
        fscanf(in, "%i", &a);
        fscanf(in, "%i", &b);
        fprintf(out, "%i\n", cmmdc(a, b));
    }
    return 0;
}

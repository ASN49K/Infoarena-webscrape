#include <math.h>
#include <stdio.h>
#include <stdbool.h>

int cmmdc(int nr1, int nr2)
{
    if (nr2 == 0)
    {
        return nr1;
    }

    return cmmdc(nr2, nr1 % nr2);
}

int main()
{
    FILE *in = fopen("cmmdc.in", "r");
    FILE *out = fopen("cmmdc.out", "w");

    int nr1, nr2;
    fscanf(in, "%d %d", &nr1, &nr2);

    int temp = cmmdc(nr1, nr2);
    if (temp == 1)
    {
        fprintf(out, "%d\n", 0);
    }
    {
        fprintf(out, "%d\n", cmmdc(nr1, nr2));
    }

    fflush(stdout);
    return 0;
}
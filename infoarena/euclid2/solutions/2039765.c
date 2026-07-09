#include <stdio.h>
#include <stdlib.h>

int cmmdc(int a, int b)
{
    int r = a % b;

    while (r)
    {
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}

int main()
{
    FILE *fileIn = fopen("euclid2.in", "r");
    FILE *fileOut = fopen("euclid2.out", "w");

    int T, i, a, b;

    fscanf(fileIn, "%d", &T);

    for (i = 0; i < T; i++)
    {
        fscanf(fileIn, " %d %d", &a, &b);
        fprintf(fileOut, "%d\n", cmmdc(a, b));
    }

    return 0;
}

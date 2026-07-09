#include <stdio.h>
#include <stdlib.h>

int cmmdc(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return cmmdc(b, a % b);
    }
}

int main()
{
    FILE *inputFile, *outputFile;
    int a, b, t, i;

    inputFile = fopen("euclid2.in", "r");
    outputFile = fopen("euclid2.out", "w");

    fscanf(inputFile, "%d", &t);

    for (i = 0; i < t; ++i)
    {
        fscanf(inputFile, "%d", &a);
        fscanf(inputFile, "%d", &b);

        fprintf(outputFile, "%d\n", cmmdc(a, b));
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

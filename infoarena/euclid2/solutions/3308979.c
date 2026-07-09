// https://infoarena.ro/problema/euclid2

#include <stdio.h>
#include <stdlib.h>

#define INPUT_FILE "euclid2.in"
#define OUTPUT_FILE "euclid2.out"

unsigned int computeGcd(
    unsigned int a,
    unsigned int b);

int main()
{
    unsigned int a = 0, b = 0, c = 0, t = 0;
    FILE *in = NULL, *out = NULL;

    if ((in = fopen(INPUT_FILE, "r")) == NULL)
    {
        fprintf(stderr, "failed to open input file %s\n", INPUT_FILE);
        exit(-1);
    }
    if ((out = fopen(OUTPUT_FILE, "w")) == NULL)
    {
        fprintf(stderr, "failed to open output file %s\n", OUTPUT_FILE);
        exit(-2);
    }

    fscanf(in, "%u", &t);
    while (t--)
    {
        fscanf(in, "%u %u", &a, &b);
        c = computeGcd(a, b);
        fprintf(out, "%d\n", c);
    }

    fclose(in);
    fclose(out);
    return 0;
}

unsigned int computeGcd(
    unsigned int a,
    unsigned int b)
{
    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a;
}

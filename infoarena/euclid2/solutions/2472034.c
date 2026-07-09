// https://infoarena.ro/problema/euclid2

#include <errno.h>
#include <stdio.h>

#ifdef LOCAL_DEV
void cmmdc(void)
#else
void main(void)
#endif // LOCAL_DEV
{
    FILE* in = stdin;
    FILE* out = stdout;
    int pairCount = 0, i = 0;
    int a, b, j;

#ifndef LOCAL_DEV
    if (!fopen_s(&in, "euclid2.in", "rt"))
    {
        printf_s("Failed to open input file: %d\n", errno);
        return;
    }
    if (!fopen_s(&out, "euclid2.out", "wt"))
    {
        printf_s("Failed to open output file: %d\n", errno);
        return;
    }
#endif
    if (!in || !out)
    {
        printf_s("%s\n", "Either input or output stream cannot be open");
        return;
    }
    if (fscanf_s(in, "%d", &pairCount) < 1)
    {
        printf_s("Failed to read number of pairs from input. Error: %d\n",
                 errno);
        return;
    }
    for (i = 0; i < pairCount; i++)
    {
        if (fscanf_s(in, "%d %d", &a, &b) < 2)
        {
            printf_s(
                "Failed to read required arguments from input. Error: %d\n",
                errno);
            return;
        }
        j = a > b ? a : b;
        while (j > 1)
        {
            if (a % j == 0 && b % j == 0)
            {
                break;
            }
            j--;
        }
        fprintf_s(out, "%d\n", j);
    }
}
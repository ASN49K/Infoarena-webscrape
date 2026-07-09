// https://infoarena.ro/problema/euclid2

#include <errno.h>
#include <stdio.h>

#ifdef LOCAL_DEV
void cmmdc(void)
#else
int main(void)
#endif // LOCAL_DEV
{
    FILE* in = stdin;
    FILE* out = stdout;
    int pairCount = 0, i = 0;
    int a, b, j;

#ifdef LOCAL_DEV
    in = fopen("euclid2.in", "rt");
    out = fopen("euclid2.out", "wt");
#endif
    if (!in || !out)
    {
        printf("%s\n", "Either input or output stream cannot be open");
        return;
    }
    if (fscanf(in, "%d", &pairCount) < 1)
    {
        printf("Failed to read number of pairs from input. Error: %d\n",
                 errno);
        return;
    }
    for (i = 0; i < pairCount; i++)
    {
        if (fscanf(in, "%d %d", &a, &b) < 2)
        {
            printf(
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
        fprintf(out, "%d\n", j);
    }
#ifndef LOCAL_DEV
    return 0;
#endif // !LOCAL_DEV
}
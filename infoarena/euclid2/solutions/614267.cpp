#include <stdio.h>

int cmmdc(int a, int b)
{
    int c = 0;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

int main()
{
    FILE *fin = fopen("euclid2.in", "r");
    FILE *fout = fopen("euclid2.out", "w");

    int pairCnt = 0, a, b;
    fscanf(fin, "%d", &pairCnt);
    for (int i = 0; i < pairCnt; i++)
    {
        fscanf(fin, "%d %d", &a, &b);
        fprintf(fout, "%d\n", cmmdc(a, b));
    }

    return 0;
}

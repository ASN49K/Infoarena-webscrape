// Algoritmul lui Euclid
// Cel mai mare divizor comun dintre doua numere naturale a si b este cel mai mare numar natural pozitiv d care divide ambele numere.

#include <stdio.h>
#include <stdlib.h>

int cmmdc(int a, int b)
{
    if(b == 0)
        return a;
    else
        return cmmdc(b, a % b);
}

int main()
{
    FILE *f, *g;
    int T, a, b, i;

    f = fopen("euclid2.in", "r");
    g = fopen("euclid2.out", "w");

    fscanf(f, "%d", &T);

    for(i = 0; i < T; i++)
    {
        fscanf(f, "%d %d", &a, &b);
        fprintf(g, "%d\n", cmmdc(a, b));
    }

    fclose(f);
    fclose(g);

    return 0;
}

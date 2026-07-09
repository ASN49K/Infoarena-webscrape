#include <stdio.h>
#include <stdlib.h>

int c(int a, int b)
{
    int aux;
    while(b!=0)
    {
        aux=a;
        a=b;
        b=aux % a;
    }
    return a;
}

int main()
{
    int i, a, b, n;
    FILE *fin, *fout;

    fin = fopen("euclid2.in", "r");
    fout = fopen("euclid2.out", "w");
    fscanf(fin, "%d", &n);
    for (i=0; i<n; i++)
    {
        fscanf(fin, "%d %d", &a, &b);
        fprintf(fout, "%d\n", c(a, b));
    }
    return 0;
}

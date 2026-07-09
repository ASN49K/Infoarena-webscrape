#include <stdio.h>

int cmmdc(int a, int b)
{
    int aux;

    while (b != 0)
    {
        aux = b;
        b = a % b;
        a = aux;
    }

    return a;
}

int main()
{
    FILE *in;
    FILE *out;

    in = fopen("euclid2.in", "r");
    out = fopen("euclid2.out", "w");

    int n;
    int a, b;
    fscanf(in, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        fscanf(in, "%d %d", &a, &b);
        fprintf(out, "%d\n", cmmdc(a,b));
    }

    fclose(in);
    fclose(out);
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

FILE *f, *g;

int cmmdc(int a, int b)
{
    if(b == 0) return a;
    return cmmdc(b, a % b);
}

int main()
{
    f = fopen("euclid2.in", "r");
    g = fopen("euclid2.out", "w");
    int n;
    fscanf(f, "%d", &n);
    while(n--)
    {
        int a, b;
        fscanf(f, "%d %d", &a, &b);
        if(b > a)
        {
            int aux = a;
            a = b;
            b = aux;
        }
        fprintf(g, "%d\n", cmmdc(a, b));
    }
    fclose(f);
    fclose(g);


    return 0;
}

/*
 * Algoritmul lui Euclid
 */

#include<stdio.h>

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    FILE* f = fopen("euclid2.in", "r");
    FILE *g = fopen("euclid2.out", "w");

    int a, b, c, n, i;
    fscanf(f, "%d", &n);
    for(i = 0; i < n; ++i) {
        fscanf(f, "%d", &a);
        fscanf(f, "%d", &b);
        c = gcd(a,b);
        fprintf(g, "%d\n", c);
    }

    fclose(f);
    fclose(g);
    return 0;
}



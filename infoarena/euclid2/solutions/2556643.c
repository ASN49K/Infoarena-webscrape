#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    //printf("%d", gcd(24, 18));
    FILE *fin=fopen("euclid.in", "r");
    FILE *fout=fopen("euclid.out", "w");
    int t;
    fscanf(fin, "%d", &t);
    for (int i=1; i<=t; i++)
    {
        int a; int b;
        fscanf(fin, "%d %d\n", &a, &b);
        int res=gcd(a, b);
        fprintf(fout, "%d\n", res);
    }
    return 0;
}

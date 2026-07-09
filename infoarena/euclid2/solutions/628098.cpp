#include <cstdlib>
#include <iostream>
#include <stdio.h>

int i, x, y;

int cmmdc(int x, int y)
{
    if (y==0) return x;
    return cmmdc(y, x % y);
}

int main()
{
    FILE *fin = fopen("euclid2.in", "r");
    FILE *fout = fopen("euclid2.out", "w");

    fscanf(fin, "%d", &i);
    for (; i; --i)
    {
        fscanf(fin, "%d %d", &x, &y);
        fprintf(fout, "%d\n", cmmdc(x, y));
    }        

    return 0;
}

//1. Algoritmul lui Euclid cmmdc
#include <stdio.h>
#include <stdlib.h>

long cmmdc(long a, long b)
{
    long c;

    while(b!=0)
    {
        c=b;
        b=a%b;
        a=c;
    }
    return a;
}

int main()
{
    FILE *fin, *fout;
    long i, T, a, b;

    fin=fopen("euclid2.in", "r");
    fout=fopen("euclid2.out", "w");

    if(fin==0) return;

    fscanf(fin, "%ld", &T);

    for(i=1;i<=T;i++)
    {
        fscanf(fin,"%ld %ld", &a, &b);
        fprintf(fout, "%ld\n", cmmdc(a,b));
    }

    fclose(fin);
    fclose(fout);

    return 0;
}

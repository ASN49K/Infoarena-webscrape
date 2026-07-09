#include <iostream>
#include <stdio.h>

typedef unsigned long ulong;
using namespace std;

ulong cmmdc( ulong a, ulong b)
{
    if (!b)
        return a;
    else 
        return cmmdc(b, a%b);
}

int main()
{
    ulong t,a,b,c,i;
    FILE *fin, *fout;
    fin  = fopen("euclid2.in", "r");
    fout = fopen("euclid2.out", "w");

    fscanf(fin,"%ul",&t);
    
    for (i=0;i<t;i++)
    {
        fscanf(fin,"%ul %ul", &a, &b);
        fprintf(fout,"%ul\n", cmmdc(a,b));
    }
    
    fclose(fin);
    fclose(fout);
    return 0;
}
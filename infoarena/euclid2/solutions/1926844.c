#include <stdio.h>
#include <stdlib.h>

unsigned long euc(unsigned long a,unsigned long b)
{
    unsigned long r;
    while(b)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    FILE *pf,*po;
    pf = fopen("euclid2.in","r");
    po = fopen("euclid2.out","w");
    unsigned long T,a,b;
    fscanf(pf,"%lu",&T);
    if(T<1 || T>100000)return 0;
    int i;
    for(i = 1 ;i <= T;i++)
    {
        fscanf(pf,"%lu %lu",&a,&b);
        if(a<2 || b<2 || a>2000000000 || b>2000000000)return 0;
        fprintf(po,"%lu\n",euc(a,b));
    }
    fclose(pf);
    fclose(po);
    return 0;
}

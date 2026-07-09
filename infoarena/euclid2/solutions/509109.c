#include <stdio.h>
#include <stdlib.h>
FILE *f,*g;
int main()
{
    f=fopen("euclid2.in","r");
    g=fopen("euclid2.out","w");
    unsigned long T,a,b,r;
    fscanf(f,"%lu",&T);
    unsigned long i;
    for(i=1;i<=T;i++)
    {
        fscanf(f,"%lu%lu",&a,&b);
        r=a%b;
        while(r)
        {
            a=b;
            b=r;
            r=a%b;
        }
        fprintf(g,"%lu\n",b);
    }
    fclose(f);
    fclose(g);
    return 0;
}

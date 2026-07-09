#include <stdio.h>
long int cmmdc (long int a, long int b);
int i;
long int a1, a2, divizor,t;
FILE *in, *out;
int main(void)
{
    in=fopen("cmmdc.in","rt");
    out=fopen("cmmdc.out","wt");\
    fscanf(in, "%d",&t);
    for(i=1;i<=t;i++)
    {
        fscanf(in, "%ld%ld",&a1,&a2);
        divizor=cmmdc(a1, a2);
        fprintf(out, "%ld\n",divizor);
    }

    fclose(in);
    fclose(out);
    return 0;
}
long int cmmdc (long int a, long int b)
{
    long int r=a%b;
    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

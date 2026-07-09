#include <stdio.h>

int cmmdc(long a, long b)
{
    int r;
    for (r = a%b; r!=0; a=b, b=r, r=a%b)
        ;
    return b;
}

int main()
{
    FILE *in,*out;
    long a,b;
    short ok;
    in = fopen("cmmdc.in","r");
    ok = fscanf(in, "%ld %ld",&a,&b);
    if (ok);
    fclose(in);

    a = cmmdc(a,b);

    out = fopen("cmmdc.out","w");
    fprintf(out, "%ld", a);
    fclose(out);
    return 0;
}

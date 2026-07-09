#include <stdio.h>

int cmmdc(long a, long b)
{
    long r;
    for (r = a%b; r!=0; a=b, b=r, r=a%b)
        ;
    return b;
}

int main()
{
    FILE *in,*out;
    long a,b;
    short ok;
    int n;
    in = fopen("euclid2.in","r");
    out = fopen("euclid2.out","w");
    fscanf(in, "%d",&n);
    while (n--)
    {
        ok = fscanf(in, "%ld %ld",&a,&b);
        if (ok);
        fprintf(out, "%d\n", cmmdc(a,b));
    }
    fclose(in);
    fclose(out);
    return 0;
}

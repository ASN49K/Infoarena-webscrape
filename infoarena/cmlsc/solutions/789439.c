#include <stdio.h>
#include <math.h>

void swap(long a, long b)
{
    long t;
    t=a;
    a=b;
    b=t;
}

long cmmdc(long a,long b)
{
    long r;
    if (a<b)
        swap(a,b);
    r=a%b;

    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main()
{
    FILE *f=fopen("cmmdc.in","r");
    FILE *g=fopen("cmmdc.out","w");
    long a,b,d;
    fscanf(f,"%ld%ld",&a,&b);
    if((d=abs(cmmdc(a,b)))<=30000)
        fprintf(g,"%ld",d);

    fclose(stdin);
    fclose(stdout);
    return 0;
}

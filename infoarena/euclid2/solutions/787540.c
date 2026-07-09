#include <stdio.h>

void swap(long a, long b)
{
    long t;
    t=a;
    a=b;
    b=t;
}

long euclid(long a,long b)
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
    FILE *f=fopen("euclid.in","r");
    FILE *g=fopen("euclid.out","w");
    long a,b;
    int T;

    fscanf(f,"%d",&T);
    if(T>=1 && T<=100000)
    {
        for(;T;--T)
        {
            fscanf(f,"%ld %ld",&a,&b);
            fprintf(g,"%ld\n",euclid(a,b));
        }
    }
    else exit(1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

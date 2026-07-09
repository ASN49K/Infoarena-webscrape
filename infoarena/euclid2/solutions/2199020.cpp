#include <stdio.h>

unsigned cmmdc(unsigned a,unsigned b)
{
    unsigned c,r;
    if(b==0)
        return a;
    else
        return cmmdc(b,a%b);
}

int main()
{
    unsigned n,a,b,i;
    FILE *f,*g;

    f=fopen("euclid2.in","r");
    g=fopen("euclid2.out","w");

    fscanf(f,"%u",&n);
    for(i=1;i<=n;i++)
    {
        fscanf(f,"%u%u",&a,&b);
        fprintf(g,"%u\n",cmmdc(a,b));
    }
}

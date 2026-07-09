#include <stdio.h>

FILE *f,*g;
long n,i;

long x,y;

long c(long a,long b)
{
     int r;
     r=a%b;
     while (r)
     {
           a=b;
           b=r;
           r=a%b;
     }
     return b;
}
int main()
{
    f = fopen("euclid2.in","r");
    g = fopen("euclid2.out","w");
    fscanf(f,"%ld",&n);
    for (i=1;i<=n;i++)
    {
        fscanf(f,"%ld %ld",&x,&y);
        fprintf(g,"%ld\n",c(x,y));
    }
    fclose(f);
    fclose(g);
    return 0;
}

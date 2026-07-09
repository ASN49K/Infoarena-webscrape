#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long int euclid(long int a, long int b)
{
    if(b>a) return euclid(b,a);
    if(b==0) return a;
    return euclid(b,a%b);
}

int main()
{
    FILE *f,*g;
    long int t,a,b,i;
    f=fopen("euclid2.in","r");
    g=fopen("euclid2.out","w");

    fscanf(f,"%ld",&t);
    for(i=0;i<t;i++)
    {
        fscanf(f,"%ld%ld",&a,&b);
        fprintf(g,"%ld\n",euclid(a,b));
    }

    fclose(f);
    fclose(g);
    return 0;
}

#include <stdio.h>

#define SWAP(a,b) int t;t=a;a=b;b=t;

int euclid(int a,int b)
{
    int r;
    if (a<b)
    {
        SWAP(a,b);
    }
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
    int a,b,n,i;

    fscanf(f,"%d",&n);

    for(i=0;i<n;i++)
    {
        fscanf(f,"%d",&a);
        fscanf(f,"%d",&b);
        fprintf(g,"%d\n",euclid(a,b));
    }
    fclose(f);
    fclose(g);
    return 0;
}

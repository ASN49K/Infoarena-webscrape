#include <stdio.h>

int euclid(int a, int b)
{
    while(a!=b)
    {
        if(a>b)
        a-=b;
        else
        b-=a;
    }
    return a;
}

int main()
{
    int k, a, b;
    FILE *in, *ie;
    in=fopen("euclid2.in","r");
    ie=fopen("euclid2.out","w");
    fscanf(in,"%d",&k);
    int i;
    for(i=0;i<k;i++)
    {
        fscanf(in,"%d %d",&a, &b);
        fprintf(ie,"%d\n",euclid(a,b));
    }
    fclose(in);
    fclose(ie);
}


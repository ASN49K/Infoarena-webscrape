#include <stdio.h>
#include <stdlib.h>

int euclid(int a,int b)
{
    while(a!=b)
    {
        if(a>b)
            a=a-b;
        if(a<b)
            b=b-a;
    }
    return a;
}

int main()
{
    int n,b,c,i;
    FILE *f,*g;
    f=fopen("euclid2.in","r");
    g=fopen("euclid2.out","w");
    fscanf(f,"%d",&n);
    for(i=0;i<n;i++)
    {
        fscanf(f,"%d",&b);
        fscanf(f,"%d",&c);
        fprintf(g,"%d\n",euclid(b,c));
    }
    fclose(f);
    fclose(g);
    return 0;
}

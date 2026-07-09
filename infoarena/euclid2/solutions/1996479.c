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
    int n,b,c,i,x;
    FILE *f,*g;
    f=fopen("a.in","r");
    g=fopen("b.out","w");
    fscanf(f,"%d",&n);
    for(i=0;i<n;i++)
    {
        fscanf(f,"%d",&b);
        fscanf(f,"%d",&c);
        x=euclid(b,c);
        fprintf(g,"%d\n",x);
    }
    fclose(f);
    fclose(g);
    return 0;
}

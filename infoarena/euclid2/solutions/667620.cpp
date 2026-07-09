#include<stdio.h>
int n,x,y,rest;

int euclid(int a,int b)
{
    int r=a%b;
    if(!r) return b;
    return euclid(b,r);
}

int main()
{
    FILE *f=fopen("euclid2.in","r");
    FILE *g=fopen("euclid2.out","w");
    fscanf(f,"%d",&n);
    for(int i=0;i<n;++i)
    {
        fscanf(f,"%d%d",&x,&y);
        fprintf(g,"%d\n",euclid(x,y));
    }
    fclose(f);
    fclose(g);
    return 0;
}

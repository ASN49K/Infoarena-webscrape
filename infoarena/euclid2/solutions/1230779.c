#include <stdio.h>
#include <stdlib.h>
int cmmdc(int a,int b)
{
    while(a!=b)
        if(a>b)a=a-b;
        else b=b-a;
    return a;
}

int main()
{
    int T,a,b;
    FILE *f=fopen("euclid2.in","r");
    if(f==NULL)
    {
        perror("EROARE");
        exit(1);
    }
    FILE *g=fopen("euclid2.out","w");
    if(g==NULL)
    {
        perror("EROARE");
        exit(1);
    }
    fscanf(f,"%d",&T);
    for(;T;--T)
    {
      fscanf(f,"%d %d",&a,&b);
      fprintf(g,"%d\n",cmmdc(a,b));
    }
    return 0;
}

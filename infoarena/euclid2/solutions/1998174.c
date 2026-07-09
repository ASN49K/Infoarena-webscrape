#include <stdio.h>
#include <stdlib.h>
int cmmdc(int a,int b)
{
    if(b==0)
        return a;
    else
        return cmmdc(b,a%b);
}
int main()
{
    FILE * in=fopen("euclid2.in","r");
    FILE * out=fopen("euclid2.out","w");
    int t;
    fscanf(in,"%d",&t);
    for(int i=0; i<t; i++)
    {
        int a=0;
        int b=0;
        fscanf(in,"%d %d",&a,&b);
        if(a>=b)
            fprintf(out,"%d\n",cmmdc(a,b));
        else
            fprintf(out,"%d\n",cmmdc(b,a));
    }
    return 0;
}

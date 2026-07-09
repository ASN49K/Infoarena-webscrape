#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fin, *fout;
    fin = fopen("cmmdc.in","r");
    fout = fopen("cmmdc.out","w");
    int a,b;
    fscanf(fin,"%d%d",&a,&b);
    while(a!=b)
    {
        if(a>b) a-=b;
        else b-=a;
    }
    if(a != 1)
    fprintf(fout,"%d",a);
    else fprintf(fout,"0");
    return 0;
}

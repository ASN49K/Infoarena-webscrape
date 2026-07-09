#include<stdio.h>
long int aux,i,repetari,x,y;
FILE *in,*out;
int main()
{
    in=fopen("euclid2.in","rt");
    out=fopen("euclid2.out","wt");
    fscanf(in,"%ld",&repetari);

    for(i=1;i<=repetari;i++)
    {
        fscanf(in,"%ld%ld",&x,&y);
        while(y)
        {
            aux=x%y;
            x=y;
            y=aux;
        }
        fprintf(out,"%ld ",x);
    }

    return 0;
}

#include<stdio.h>
int aux,i,repetari,x,y;
FILE *in,*out;
int main()
{
    in=fopen("euclid2.in","rt");
    out=fopen("euclid2.out","wt");
    fscanf(in,"%d",&repetari);

    for(i=1;i<=repetari;i++)
    {
        fscanf(in,"%d%d",&x,&y);
        while(y)
        {
            aux=x%y;
            x=y;
            y=aux;
        }
        fprintf(out,"%d ",x);
    }

    return 0;
}

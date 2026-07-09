#include <stdio.h>

FILE *f,*g;

int perechi=0,a,b,rez;

int main(void)
{
    f=fopen("euclid2.in","r");
    g=fopen("euclid2.out","w");
    fscanf(f,"%d",&perechi);
    int i;
    for (i=1;i<=perechi;i++)
    {
        fscanf(f,"%d %d",&a,&b);
        while(b!=0)
        {
            rez=a%b;
            a=b;
            b=rez;
        }
        fprintf(g,"%d\n",rez);
    }
    fclose(f);
    fclose(g);
    return 0;
}

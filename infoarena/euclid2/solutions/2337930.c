#include <stdio.h>

File *f=fopen("euclid2.in","r"),*g=fopen("euclid.out","w");

int perechi=0,a,b,rez;

int main(void)
{
    fscanf(f,"%d",&perechi);
    for (int i=1;i<=perechi;i++)
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
    return 0;
}

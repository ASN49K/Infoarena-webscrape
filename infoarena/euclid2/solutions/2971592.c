#include <stdio.h>
#include <stdlib.h>
unsigned int Euclid(unsigned int a,unsigned int b)
{
    unsigned int r=0;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }

    return a;

}
int main()
{
    FILE *pf=fopen("euclid2.in","r");
    FILE *fp=fopen("euclid2.out","w");

     unsigned int T=0,a,b;
     fscanf(pf,"%u",&T);
     while(T>0)
     {
         fscanf(pf,"%u %u",&a,&b);
         fprintf(fp,"u\n",Euclid(a,b));
     }

    fclose(fp);
    fclose(pf);

    return 0;
}

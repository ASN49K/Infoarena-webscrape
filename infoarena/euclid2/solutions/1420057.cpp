#include <stdio.h>

int GCD(int a, int b)
{
    if(!b) return a;
    else return GCD(b,a%b);
}


int main()
{
    int T;
    int i;
    int a,b;

    FILE* in = fopen("euclid2.in","r");
    FILE* out = fopen("euclid2.out","w");

    for(i=0;i<T;i++)
    {
        fscanf(in,"%d",&a);
        fscanf(in,"%d",&b);
        fprintf(out,"%d\n",CMMDC(a,b));
    }


    fclose(in);
    fclose(out);
}

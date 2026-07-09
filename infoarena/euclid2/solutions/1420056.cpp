#include <stdio.h>

int CMMDC(int a, int b)
{
    while(a%b!=0 && b%a!=0)
    {
        if(a > b) a=a%b;
        else b=b%a;
    }
    if(a > b) return b;
    else return a;
}

int main()
{
    int T;
    int i;
    int a,b;

    FILE* in = fopen("euclid2.in","r");
    FILE* out = fopen("euclid2.out","w");

    for(i=0;i<0;i++)
    {
        fscanf(in,"%d",&a);
        fscanf(in,"%d",&b);
        fprintf(out,"%d\n",CMMDC(a,b));
    }


    fclose(in);
    fclose(out);
}

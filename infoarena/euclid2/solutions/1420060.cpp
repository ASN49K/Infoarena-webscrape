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

    fscanf(in,"%d",&T);
    for(i=1;i<=T;i++)
    {
        fscanf(in,"%d %d",&a,&b);
        fprintf(out,"%d\n",GCD(a,b));
    }


    fclose(in);
    fclose(out);
}

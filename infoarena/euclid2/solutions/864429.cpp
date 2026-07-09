#include <stdio.h>

//Functii
int gcd(int x, int y)
{
    return y? gcd(y, x%y) : x;
}
//Variabile
FILE *in, *out;

int num,a,b;

int main()
{
    in=fopen("euclid2.in","rt");
    out=fopen("euclid2.out","wt");

    fscanf(in,"%d",&num);

    for(int i=1 ; i<=num ; ++i)
    {
        fscanf(in,"%d%d",&a,&b);
        fprintf(out,"%d\n",gcd(a,b));
    }

    fclose(in);
    fclose(out);
}

#include <stdio.h>
#include <math.h>

int AC (int a, int b)
{
    int r;
    if (a>b)
    {

    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
    }
    else
    {
    while(a != 0)
    {
        r = b % a;
        b = a;
        a = r;
    }
    return b;
    }
}

int main()
{
    FILE* f;
    FILE* g;
    f=fopen("euclid2.in","r");
    g=fopen("euclid2.out","w");

    long int a, b, T, cmmdc=0;

    fscanf(f,"%ld",&T);

    for(int i=1;i<=T;i++)
    {
        fscanf(f,"%ld%ld",&a,&b);
        fprintf(g,"%d\n", AC(a,b));
    }

    fclose(f);
    fclose(g);

}

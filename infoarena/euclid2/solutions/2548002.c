#include <stdio.h>
#include <stdlib.h>

int cmmdc(int a, int b)
{
    while(a != b)
    {
        if(a > b)
        {
            a = a-b;
        }
        else
        {
            b = b-a;
        }
    }
    return a;
}

int cmmdc_div(int a, int b)
{

    while(a != 0 && b != 0)
    {
        //printf("%d,%d\n", a, b);
        if(a > b)
        {
            a = a%b;
        }
        else
        {
            b = b%a;
        }
    }
    return (a > b)? a:b;
}

int main()
{
    FILE *fin = fopen("euclid2.in","r"), *fout = fopen("euclid2.out","w");
    int n;
    fscanf(fin,"%d",&n);
    int a, b;
    for(int i = 1; i <= n; i++)
    {
        fscanf(fin,"%d %d", &a, &b);
        fprintf(fout,"%d\n",cmmdc_div(a,b));
    }
    fclose(fin);
    fclose(fout);
    return 0;
}

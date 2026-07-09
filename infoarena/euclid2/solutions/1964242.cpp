#include<stdio.h>
FILE*f=fopen("euclid2.in","r");
FILE*g=fopen("euclid2.out","w");

int CMMDC(int a, int b)
{
    int r;
    while(b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int t, a, b;
    fscanf(f,"%d",&t);
    for(int i = 0; i < t; ++i)
    {
        fscanf(f,"%d%d",&a,&b);
        fprintf(g,"%d\n",CMMDC(a,b));
    }
    fclose(f);
    fclose(g);
    return 0;
}

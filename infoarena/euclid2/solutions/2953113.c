#include <stdio.h>

int cmmdc (int a, int b)
{
    int r;
    if (a>b)
    {
        while (b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        return a;
    }
    else
    {
        while (a!=0)
        {
            r=b%a;
            b=a;
            a=r;
        }
        return b;
    }
}

int main()
{
    FILE *f;
    FILE *g;

    f=fopen ("euclid2.in","r");
    g=fopen ("euclid2.out","w");

    int d, e;

    while (1)
    {
        if (feof(f))
        {
            break;
        }
        fscanf(f,"%d %d",&d,&e);
        fprintf(g,"%d\n",cmmdc(d,e));
    }

    fclose (f);
    fclose (g);

    return 0;
}
